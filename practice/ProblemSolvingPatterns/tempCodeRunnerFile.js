function charCount(str){
    Map<char,int> char_count;
    str.forEach(element => {
        char_count[element]++;
    });
}