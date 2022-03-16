//
// Created by bourg on 27-02-22.
//

#include "conan/Poco/MD5Engine.h"
#include "Poco/DigestStream.h"
#include "boost/circular_buffer.h"
#include <iostream>
int main(int argc, char** argv)
{
  Poco::MD5Engine md5;
  Poco::DigestOutputStream ds(md5);
  ds << "abcdefghijklmnopqrstuvwxyz";
  ds.close();
  std::cout << Poco::DigestEngine::digestToHex(md5.digest()) << std::endl;
  return 0;
}