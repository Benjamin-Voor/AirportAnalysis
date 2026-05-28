std::string readWord(std::fstream fin) {
  std::string temp, word;
  if(fin >> temp) { // same as infile != NULL

    // Read the entire first row and
    // store it in this string variable
    std::string line;

    // read an entire row and 
    // store it in a string variable 'line' 
    getline(fin, line);

    // Used for breaking words
    std::stringstream s(line);

    std::string word;
    std::getline(s,word,',');
    return word; 
  }
  std::cout << "Error: readWord" << std::endl;
  return "";
}