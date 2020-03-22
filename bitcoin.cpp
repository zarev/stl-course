#include <iostream>
#include <memory>
#include <functional>
#include <array>
#include <cstdio>

#include <curl/curl.h>
#include "json.hpp"

using namespace std;

typedef std::unique_ptr<CURL, std::function<void(CURL*)>> CURL_ptr;



class CurlHandle{
 
  private : 
    CURL_ptr curlptr;
    constexpr static auto deleter = [](CURL* c){
      curl_easy_cleanup(c);
      curl_global_cleanup();
    };

  public : 
    CurlHandle() : curlptr(curl_easy_init(), deleter) {
      curl_global_init(CURL_GLOBAL_ALL);
    }

    void setURL(string url){
      curl_easy_setopt(curlptr.get(), CURLOPT_URL, url.c_str());
    }

    CURLcode fetch(){
      return curl_easy_perform(curlptr.get());
    }

};

class Bitcoin {
  private :
    CurlHandle curlHandle; 
    static constexpr const char* API_URL = "https://blockchain.info/ticker";
  
  public : 
    Bitcoin() : curlHandle({}) {
      curlHandle.setURL(API_URL);
    }

    void fetchBitcoinData(){
      curlHandle.fetch();
    }
};


int main(){
  
  Bitcoin bitcoin; 
  bitcoin.fetchBitcoinData();
  

  return 0;
}
