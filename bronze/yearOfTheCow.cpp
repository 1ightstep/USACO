#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; 
    const vector<string> ZODIAC = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

    unordered_map<string, int> relations = {{"Bessie", 0}};
    for (int i = 0; i < n; i++) {
        string curr, und, dir, zodiac, prev;
        cin >> curr >> und >> und >> dir >> zodiac >> und >> und >> prev;
        
        int change = dir == "previous" ? -1 : 1; 
        int age = relations[prev];
        do {
            age += change;
        } while (ZODIAC[((age%12) + 12)%12] != zodiac);
        relations[curr] = age;
    }

    cout << abs(relations["Bessie"] - relations["Elsie"]);
}