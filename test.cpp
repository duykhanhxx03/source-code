std::vector <std::string> mergeStringArr(std::vector<std::string> arr1, std::vector<std::string> arr2)
{
    std::set<std::string> arr1_set (arr1.begin(), arr1.end());
    for (std::vector <std::string>::iterator it =arr2.begin(); it!=arr2.end(); it++){
        std::set<std::string>::iterator search=arr1_set.find(*it);
        if (search!=arr1_set.end()){
            arr1_set.erase(search);
        }
    }
    std::vector<std::string> res (arr1_set.begin(), arr1.end());
    return res;
}