You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

 Input: secret = "1807", guess = "7810"
Output: "1A3B"

class Solution {

public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        int cntb=0,cntc=0;
        map<int,int> mp1;
        map<int,int> mp2;
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
                cntb++;
            else
            {
                mp1[secret[i]-'0']++;
                mp2[guess[i]-'0']++;
            }
            
        }
        for(auto it:mp1)
        {
            if(mp2.find(it.first)!=mp2.end())
            cntc+=min(mp2[it.first],it.second);
        }
        string s="";
        s=to_string(cntb)+"A"+to_string(cntc)+"B";
        return s;
    }
    
};