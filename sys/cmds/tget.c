#include <stdio.h>
#include <iostream>
#include <string>
#include <curl/curl.h>
using namespace std;

string data;

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{
    for (int c = 0; c<size*nmemb; c++)
    {
        data.push_back(buf[c]);
    }
    return size*nmemb;
}

int sht_tget(char **args)
{
  if (args[1] == "-h" || args[1] == "--help")
  {
    printf("Usage: tget <URL> <filename>\n");
    printf("\tSave a file from <URL> to <filename>.\n");
    return 1;
  }

  //int argc = sizeof(args)/sizeof(*args);
  /*if (args[2] != args[3])
  {
    printf("sht: Error! To few arguments!\nsht: Usage:\n\ttget <URL> <FileNameToDownload>\n");
  }
  else
  {*/
    //HRESULT hr = URLDownloadToFile ( NULL, _T(args[1]), _T(args[2]), 0, NULL );

    //printf("sht: We are so sorry, but this function is disabled. Contact the creators.\n");

    CURL* curl;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, args[1]);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    curl_easy_perform(curl);

    cout << endl << data << endl;
    cin.get();

    curl_easy_cleanup(curl);
    curl_global_cleanup();

  //}

	return 1;
}
