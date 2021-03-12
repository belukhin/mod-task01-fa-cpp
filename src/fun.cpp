unsigned int faStr1(const char *str)
{
    unsigned int counter = 0;
    unsigned int i = 0;
    bool inWord = false;
    bool goodWord = false;

    while(str[i] != '\0'){
        if(!inWord && str[i] != ' '){ 
            goodWord = true;
            inWord = true;
        } 
        if (inWord && str[i] == ' '){
            inWord = false;
            if(goodWord) counter++;    
        }
        if(inWord && str[i] >= 48 && str[i] <= 57)
            goodWord = false;
        i++;
    }
    return counter;
}
unsigned int faStr2(const char *str)
{
    unsigned int i = 0;
    unsigned int counter = 0;
    bool inWord = false;
    bool goodWord = false;
    while(str[i] != '\0') {
        if(str[i] != ' ' && !inWord) {
            inWord = true;
            if(str[i] >= 65 && str[i] <= 90) {
                goodWord = true;
                i++;
            }
        }
        if(str[i] == ' ' && inWord) {
            inWord = false;
            if(goodWord) counter++;
        }
        if( inWord && (str[i] <= 96 || str[i] >= 123) )
            goodWord = false;
        i++;
    }
    if(str[i - 1] != ' ' && goodWord) counter++;

    return counter;
}
unsigned int faStr3(const char *str)
{
    unsigned int i = 0;
    double result = 0;
    unsigned int wordCounter = 0;
    unsigned int letterCounter = 0;
    bool inWord = false;

    while(str[i] != '\0') {
        if(str[i] != ' ' && !inWord) inWord = true;
        if(str[i] == ' ' && inWord){
            inWord = false;
            wordCounter++;
        }
        if(inWord) letterCounter++;
        i++;
    }

    if(str[i-1] != ' ') wordCounter++;
    result = (double)letterCounter / (double)wordCounter;
    result+=0.5;
    return result;
}