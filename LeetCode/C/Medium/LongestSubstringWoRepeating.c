/*      INSTRUCTIONS:
Given a string s, find the length of the longest substring without repeating characters.
*/

int lengthOfLongestSubstring(char *s) {
    int lastIndex[128];  // 128 Characters
    for(int i = 0; i < 128; i++) { lastIndex[i] = -1;}  // -1 indicates character not seen yet
    int maxLength = 0;   // Length of longest substring
    int start = 0;       // Starting index of the current substring
    for(int i = 0; s[i] != '\0'; i++){
        if(lastIndex[s[i]] >= start){ start = lastIndex[s[i]] + 1;}
        lastIndex[s[i]] = i;
        int currentLength = i - start + 1;
        if(currentLength > maxLength){maxLength = currentLength;}
    } return maxLength;
}