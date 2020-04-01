#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <tuple>  

using namespace std;

//assuming input is a .txt file
//assuming that the background is always sea
//assuming biggest rec is land

enum Terrain{sea, land};

class Rectangle{
public:
	double x0,y0,x1,y1;
	double area;
	Rectangle * parent{NULL};
	vector<Rectangle*> children;
	Terrain type;

	Rectangle(vector<double> corners){
		x0 = corners[0];
		y0 = corners[1];
		x1 = corners[2];
		y1 = corners[3];
		area = (y1 - y0) * (x1 - x0);
	}
	~Rectangle(){}

	void setParent(Rectangle &newParent) {parent = &newParent;}

  //overlading extractor operator for custom rectangle output
  friend ostream& operator<<(ostream& os, const Rectangle& rec){
    return os << "["  << rec.x0 << " " << rec.y0 <<  
                 " "  << rec.x1 << " " << rec.y1 << 
                 "]";
  }
};

//check if rec2 is inside rec1
bool isInside(const Rectangle& rec1, const Rectangle& rec2){
      return (rec1.x0 <= rec2.x0 && rec1.y0 <= rec2.y0 &&
              rec1.x1 >= rec2.x1 && rec1.y1 >= rec2.y1);
}

//predicate for sorting
bool isGreater(const Rectangle& rec1, const Rectangle& rec2) {return (rec1.area > rec2.area);}

//import rectangles from a file
//generate objects for all coordinate vectors
tuple<vector<Rectangle>, int> importRecs(string filePath){
  ifstream file(filePath);

  //first line
  string str;  
  getline(file, str);
  int num_recs = stoi(str);

  vector<Rectangle> recs;
  recs.reserve(num_recs);

  //convert every line into a vector<double>
  while (getline(file, str, '\n')){
    vector<double> curr_coords;
    stringstream ss(str);
    curr_coords = vector<double>{istream_iterator<double>(ss), istream_iterator<double>()};
    recs.push_back(Rectangle(curr_coords));
  }
  return make_tuple(recs, num_recs);
}

//set labels from head down
//largest rectangle would have NULL as parent
void setLabels(Rectangle& rec){
	if  (!rec.parent) rec.type = land;	
	else  rec.type = (rec.parent->type==land)? sea : land;

  //keep moving down the tree
	for(int i = 0; i < rec.children.size(); i++) setLabels(*(rec.children[i]));

}

int main(int argc, char* argv[]){

  int num_recs;
  vector<Rectangle> recs;
  
  //combine the tuple output from import function
  if(argc < 2) {cerr << "Please provide a text file. "; return 0;}

  //loading rectangles
  // tie(recs, num_recs) = importRecs(argv[1]);
  tie(recs, num_recs) = importRecs("input.txt");


  // cout << "\nOriginal list: \n";
  // for (Rectangle& rec : recs) cout << rec << '\n';

  sort(recs.begin(), recs.end(),isGreater);
  // cout << "\nSorted list: \n";
  // for (Rectangle& rec : recs) cout << rec << '\n';

  //build tree
  for(int i = 0; i < num_recs; i++){
    for(int j = i + 1; j < num_recs; j++){
      if(isGreater(recs[i], recs[j]) && isInside(recs[i], recs[j])){
         recs[j].setParent(recs[i]);
      }
    }
  }

  //find edges
  for(int i = 0; i<num_recs;i++){
    if (recs[i].parent) recs[i].parent->children.push_back(&recs[i]);
  }

  //set labels
	for(Rectangle& rec: recs) if (!rec.parent) setLabels(rec);
		
  //count land recs
  int count = 0;
  for(Rectangle& rec : recs) if(rec.type == land) count ++;

  cout << count;
  return count;
} 