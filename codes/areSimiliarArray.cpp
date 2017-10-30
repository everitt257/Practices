struct diffs{
    std::vector<int> Indexes;
    bool result;
};


bool areSimilar(std::vector<int> a, std::vector<int> b) {
    diffs output = CompareLists(a,b);
    if(output.result)
        return true;
    else if(output.Indexes.size() == 2){
        int first = output.Indexes[0];
        int second = output.Indexes[1];
        if(a[first] == b[second] && a[second] == b[first])
            return true;
        else
            return false;
    }
    else
        return false;
}

diffs CompareLists(std::vector<int> a, std::vector<int> b) {
    diffs output;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]){
            output.Indexes.push_back(i);
        }
    }
    if(output.Indexes.size() == 0)
        output.result = true;
    else
        output.result = false;
    
    return output;
}
