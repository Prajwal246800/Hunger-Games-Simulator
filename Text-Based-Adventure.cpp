#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <ctime>

using namespace std;

class Tribute {
    string name;     // Attributes
    int defense;
    int speed;
    int strength;
    int camouflage;
    int district;
    string weapon;
    vector<string> inventory;

    public :
    Tribute(string na, int df, int sp, int st, int cf, int ds, string wp) : name(na), defense(df), speed(sp), strength(st), camouflage(cf), district(ds), weapon(wp) {}  // Constructor
    void add_df(int num);           // Editors
    void sub_df(int num);
    void add_sp(int num);
    void sub_sp(int num);
    void add_st(int num);
    void sub_st(int num);
    void add_cf(int num);
    void sub_cf(int num);
    void add_iv(string item);             // Add to inventory    
    bool sub_iv(string item);             // Remove from inventory

    string get_na();                // Getters
    int get_df();
    int get_sp();
    int get_st();
    int get_cf();
    int get_ds();
    string get_wp();
    void get_iv();

    ~Tribute();                     // Destructor

};

bool introduction();                // Functions
Tribute character_selection();
bool character_preview(Tribute user);
bool if_dead(int trait, int liveChance);
void entrance(Tribute user);
void encounter1(Tribute user);
void encounter2(Tribute user);
void encounter3(Tribute user);
void encounter4(Tribute user);
void encounter5(Tribute user);
void encounter6(Tribute user);
void win();
void dead(string cod);

int main() {
    bool selection = introduction();                                // Checking if user wants to play
    if (!selection) {
        cout << "\n";
        cout << "Maybe next time!" << "\n"; 
        cout << "\n";
        return 0;
    }

    Tribute user = character_selection();                           // User picks valid tribute
    while (user.get_na() == "default") { 
        cout << "\nSorry, wrong selection. Please try again:\n";
        user = character_selection();
    }

    if (!character_preview(user)) {                                 // Second validation to start the game
        cout << "\n";
        cout << "Maybe next time!" << "\n"; 
        cout << "\n";
        return 0;
    }

    entrance(user);                                                 // Hunger Games Begin!

    return 0;
}

void Tribute::add_df(int num) { defense += num; }

void Tribute::sub_df(int num) { defense -= num; }

void Tribute::add_sp(int num) { speed += num; } 

void Tribute::sub_sp(int num) { speed -= num; }

void Tribute::add_st(int num) { strength += num; }

void Tribute::sub_st(int num) { strength -= num; }

void Tribute::add_cf(int num) { camouflage += num; }

void Tribute::sub_cf(int num) { camouflage -= num; }

void Tribute::add_iv(string item) {
    inventory.push_back(item);
}

bool Tribute::sub_iv(string item) {
    for (int i = 0; i < inventory.size(); i++) {
        if (item == inventory[i]) {
            inventory[i].erase();
            return true;
        }
    }
    return false;
}

string Tribute::get_na() { return name; }

int Tribute::get_df() { return defense; }

int Tribute::get_sp() { return speed; }

int Tribute::get_st() { return strength; }

int Tribute::get_cf() { return camouflage; }

int Tribute::get_ds() { return district; }

string Tribute::get_wp() { return weapon; }

void Tribute::get_iv() {
    cout << "Your inventory: ";
    for (int i = 0; i < inventory.size(); i++) {
        if (i == inventory.size() - 1) {
            cout << inventory[i]; break;
        }
        cout << inventory[i] << ", ";
    }
}

Tribute::~Tribute() {}

bool introduction() {
    string user;
    cout << "\n";
    cout << "Welcome to the 74th Annual Hunger Games. . . Are you ready to begin? (Yes or No): ";
    cin >> user;
    if (user == "Yes" || user == "yes" || user == "Y" || user == "y") { return true; }
    else { return false; }
}

Tribute character_selection() {
    int selection;
    cout << "\nSelect your tribute!" << "\n";
    cout << "\n1. Marvel \n2. Glimmer \n3. Cato \n4. Clove \n5. Foxface \n6. Thresh \n7. Rue \n8. Peeta \n9. Katniss \n \nYour selection is: ";
    while (!(cin >> selection)) {
        cout << "\nSorry, wrong selection. Please try again:\n";
        cout << "\nSelect your tribute!" << "\n";
        cout << "\n1. Marvel \n2. Glimmer \n3. Cato \n4. Clove \n5. Foxface \n6. Thresh \n7. Rue \n8. Peeta \n9. Katniss \n \nYour selection is: ";
        cin.clear();
        cin.ignore(123, '\n');  
    }

    switch (selection) {
        case 1 : {                                                     // District 1
            Tribute _1("Marvel", 30, 80, 50, 40, 1, "Spear");          // Specialty Luxury
            return _1;
        }
        case 2 : {
            Tribute _2("Glimmer", 30, 80, 30, 60, 1, "Bow");
            return _2;
        }
        case 3 : {                                                     // District 2
            Tribute _3("Cato", 60, 30, 90, 20, 2, "Sword");            // Specialty Guns
            return _3;
        }
        case 4 : {
            Tribute _4("Clove", 70, 90, 20, 20, 2, "Knife");
            return _4;
        }
        case 5 : {                                                     // District 5
            Tribute _5("Foxface", 20, 80, 10, 90, 5, "Knife");         // Specialty Energy
            return _5;
        }
        case 6 : {                                                      // District 11
            Tribute _6("Thresh", 60, 20, 100, 20, 11, "Sword");         // Specialty Agriculture
            return _6;
        }
        case 7 : {
            Tribute _7("Rue", 10, 80, 10, 100, 11, "Knife");
            return _7;
        }
        case 8 : {                                                      // District 12
            Tribute _8("Peeta", 10, 10, 80, 100, 12, "Sword");          // Specialty Mining
            return _8;
        }
        case 9 : {
            Tribute _9("Katniss", 80, 50, 50, 20, 12, "Bow");
            return _9;
        }
        default : {
            Tribute def("default", 0, 0, 0, 0, 0, "");
            return def;
        }
    }
}

bool character_preview(Tribute user) {
    string selection;
    cout << "\nYou have selected " << user.get_na() << " from District " << user.get_ds() <<  ", these are your skill stats:\n";
    cout << "\nDefense - " << user.get_df() << "\nSpeed - " << user.get_sp() << "\nStrength - " << user.get_st() << "\nCamouflage - " << user.get_cf() << "\n";
    cout << "\nAre you now ready to start the Hunger Games? (Yes or No): "; cin >> selection;
    if (selection == "Yes" || selection == "yes" || selection == "Y" || selection == "y") { return true; }
    else { return false; }
}

bool if_dead(int trait, int liveChance) {
    srand(time(0)); int chance = rand() % 100 + 1;
    if (((trait + liveChance) / chance) < 1) {
        return true;
    }
    return false;
}

void entrance(Tribute user) {
    int selection;
    cout << "\n. . .\n\n"; sleep(3); cout << "You are entering the arena. . .\n"; sleep(3);
    cout << "\nYou are in a grass field and have a large forest behind you. . .\n"; sleep(4); 
    cout << "\nYou see the the Cornucopia with supplies and weapons in front of you, as well as backpacks on the outer edge of the center with unknown items. . .\n";
    sleep(6); cout << "\nYou start to hear a countdown. . ."; cout << "\n"; cout << "\n3"; sleep(2);
    cout << "\n2"; sleep(2); cout << "\n1"; sleep(2); cout << "\n"; sleep(2); cout << "\nA cannon has fired, the Hunger Games have started!\n";
    sleep(3); cout << "\nEveryone starts running around you, where do you want to run?\n\n1. Cornucopia\n2. Backpack\n3. Forest\n4. Check Inventory\n\nYour Selection is: ";
    while ((!(cin >> selection)) || (selection < 1) || (selection >= 4)) {
        if (selection == 4) {
            cout << "\nYour Inventory is currently empty\n";
            cout << "\n1. Cornucopia\n2. Backpack\n3. Forest\n4. Check Inventory\n\nYour Selection is: ";
            continue;
        }
        cout << "\nSorry, wrong selection. Please try again:\n";
        cout << "\n1. Cornucopia\n2. Backpack\n3. Forest\n4. Check Inventory\n\nYour Selection is: ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    
    switch(selection) {
        case 1 : {
            cout << "\nYou run to the Cornucopia and pass by everyone, you have a short amount of time before someone notices you, you grab a backpack and a " << user.get_wp() << " and run.\n";
            sleep(6); cout << "\nHere are your updated stats:\n"; sleep(3);
            user.add_df(20); user.add_st(20); user.sub_sp(20);
            cout << "\nDefense - " << user.get_df() << "\nSpeed - " << user.get_sp() << "\nStrength - " << user.get_st() << "\nCamouflage - " << user.get_cf() << "\n\n";
            user.add_iv("Rope"); user.add_iv("Empty water bottle"); user.add_iv("Knife"); user.add_iv("Matches"); user.add_iv(user.get_wp());
            encounter1(user);
            break;
        }
        case 2 : {
            cout << "\nYou run to the backpacks around the Cornucopia, you have a short amount of time before someone notices you, you grab a backpack and run.\n";
            sleep(6); cout << "\nHere are your updated stats:\n"; sleep(3);
            user.add_df(10); user.add_st(10); user.sub_sp(10); 
            cout << "\nDefense - " << user.get_df() << "\nSpeed - " << user.get_sp() << "\nStrength - " << user.get_st() << "\nCamouflage - " << user.get_cf() << "\n\n";
            user.add_iv("Rope"); user.add_iv("Empty water bottle"); user.add_iv("Knife"); user.add_iv("Matches");
            encounter1(user);
            break;
        }
        case 3 : {
            cout << "\nYou run straight to the forest to avoid conflict, you pick up nothing.\n";
            sleep(6); cout << "\nHere are your updated stats:\n"; sleep(3);
            cout << "\nDefense - " << user.get_df() << "\nSpeed - " << user.get_sp() << "\nStrength - " << user.get_st() << "\nCamouflage - " << user.get_cf() << "\n\n";
            encounter1(user);
            break;
        }
    }
}

void encounter1(Tribute user) {
    int selection;
    sleep(2); cout << "While running to the forest, you see someone ahead of you. What do you want to do?\n\n1. Attack\n2. Run other way\n3. Check Inventory\n\nYour Selection is: ";
    while ((!(cin >> selection)) || (selection < 1) || (selection >= 3)) {
        if (selection == 3) {
            cout << "\n"; user.get_iv();
            cout << "\n\n1. Attack\n2. Run other way\n3. Check Inventory\n\nYour Selection is: ";
            continue;
        }
        cout << "\nSorry, wrong selection. Please try again:\n";
        cout << "\n1. Attack\n2. Run other way\n3. Check Inventory\n\nYour Selection is: ";
        cin.clear();
        cin.ignore(123, '\n');
    }

    switch (selection) {
        case 1 : {
            if (!if_dead(user.get_st(), 80)) {
                sleep(2); cout << "\nYou successfully eliminated the other tribute.\n";
                encounter2(user);
            }
            else { dead("another tribute"); }
            break;
        }
        case 2 : {
            if (!if_dead(user.get_sp(), 80)) {
                sleep(2); cout << "\nYou successfully avoided the other tribute.\n";
                encounter2(user);
            }
            else { dead("another tribute"); }
            break;
        }
    }
}

void encounter2(Tribute user) {
    int selection;
    sleep(2); cout << "\nIt starts to get dark, what do you want to do?\n\n1. Take cover\n2. Hunt for other people\n3. Check Inventory\n\nYour Selection is: ";
    while ((!(cin >> selection)) || (selection < 1) || (selection >= 3)) {
        if (selection == 3) {
            cout << "\n"; user.get_iv();
            cout << "\n\n1. Take cover\n2. Hunt for other people\n3. Check Inventory\n\nYour Selection is: ";
            continue;
        }
        cout << "\nSorry, wrong selection. Please try again:\n";
        cout << "\n1. Take cover\n2. Hunt for other people\n3. Check Inventory\n\nYour Selection is: ";
        cin.clear();
        cin.ignore(123, '\n');
    }

    switch (selection) {
        case 1 : {
            if (!if_dead(user.get_cf(), 60)) {
                sleep(2); cout << "\nYou successfully took cover for the night.\n";
                encounter3(user);
            }
            else { dead("another tribute"); }
            break;
        }
        case 2 : {
            if (!if_dead(user.get_st(), 60)) {
                sleep(2); cout << "\nYou found another tribute and eliminated them. You picked up armor and put it on. You then went to sleep for the night.\n";
                user.add_iv("Armor"); user.add_df(20);
                encounter3(user);
            }
            else { dead("another tribute"); }
            break;
        }
    }
}

void encounter3(Tribute user) {
    int selection;
    sleep(2); cout << "\nYou wake up parched and in need of water, what do you want to do?\n\n1. Find water\n2. Ignore your body\n3. Check Inventory\n\nYour Selection is: ";
    while ((!(cin >> selection)) || (selection < 1) || (selection >= 3)) {
        if (selection == 3) {
            cout << "\n"; user.get_iv();
            cout << "\n\n1. Find water\n2. Ignore your body\n3. Check Inventory\n\nYour Selection is: ";
            continue;
        }
        cout << "\nSorry, wrong selection. Please try again:\n";
        cout << "\n1. Find water\n2. Ignore your body\n3. Check Inventory\n\nYour Selection is: ";
        cin.clear();
        cin.ignore(123, '\n');
    }

    switch (selection) {
        case 1 : {
            sleep(2); cout << "\nYou climb up a tree and find the nearest water source. You drink up and refill any containers you have.\n";
            if (user.sub_iv("Empty water bottle")) {
                user.add_iv("Full water bottle");
            }
            encounter4(user);
            break;
        }
        case 2 : { dead("dehydration"); break; }
    }
}

void encounter4(Tribute user) {
    int selection;
    sleep(2); cout << "\nAfter getting water, you see a group of tributes approaching you from the other side of the pond, what do you want to do?\n\n1. Defend yourself\n2. Run away\n3. Check Inventory\n\nYour Selection is: ";
    while ((!(cin >> selection)) || (selection < 1) || (selection >= 3)) {
        if (selection == 3) {
            cout << "\n"; user.get_iv();
            cout << "\n\n1. Defend yourself\n2. Run away\n3. Check Inventory\n\nYour Selection is: ";
            continue;
        }
        cout << "\nSorry, wrong selection. Please try again:\n";
        cout << "\n1. Defend yourself\n2. Run away\n3. Check Inventory\n\nYour Selection is: ";
        cin.clear();
        cin.ignore(123, '\n');
    }

    switch (selection) {
        case 1 : {
            if (!if_dead(user.get_df(), 40)) {
                sleep(2); cout << "\nYou successfully defended your position from the team of tributes. The other tributes had other weapons and armor. You take the armor and move on.\n";
                user.add_df(20);
                if (!user.sub_iv("Armor")) {
                    user.add_iv("Armor");
                }
                encounter5(user);
            }
            else { dead("other tributes"); }
            break;
        }
        case 2 : {
            if (!if_dead(user.get_sp(), 40)) {
                sleep(2); cout << "\nYou successfully ran away from the team of tributes.\n";
                encounter5(user);
            }
            else { dead("other tributes"); }
            break;
        }
    }
}

void encounter5(Tribute user) {
    int selection;
    sleep(2); cout << "\nAfter encountering the team of tributes, you realize you are hungry and scavenge. You find an apple and darkblue berries. What do you want to do?\n\n1. Eat apple\n2. Eat berries\n3. Check Inventory\n\nYour Selection is: ";
    while ((!(cin >> selection)) || (selection < 1) || (selection >= 3)) {
        if (selection == 3) {
            cout << "\n"; user.get_iv();
            cout << "\n\n1. Eat apple\n2. Eat berries\n3. Check Inventory\n\nYour Selection is: ";
            continue;
        }
        cout << "\nSorry, wrong selection. Please try again:\n";
        cout << "\n1. Eat apple\n2. Eat berries\n3. Check Inventory\n\nYour Selection is: ";
        cin.clear();
        cin.ignore(123, '\n');
    }

    switch (selection) {
        case 1 : {
            sleep(2); cout << "\nYou eat the apple and move on.\n";
            encounter6(user);
            break;
        }
        case 2 : { dead("nightlock berries"); break; }
    }
}

void encounter6(Tribute user) {
    int selection;
    sleep(2); cout << "\nThe sky quickly becomes dark and you realize that the Hunger Games are coming to an end. . .\n";
    sleep(4); cout << "\nYou start to hear growls behind you in the forest, what do you want to do?\n\n1. Defend yourself\n2. Run towards Cornucopia\n3. Hide in nearby bushes\n4. Check Inventory\n\nYour Selection is: ";
    while ((!(cin >> selection)) || (selection < 1) || (selection >= 4)) {
        if (selection == 4) {
            cout << "\n"; user.get_iv();
            cout << "\n\n1. Defend yourself\n2. Run towards Cornucopia\n3. Hide in nearby bushes\n4. Check Inventory\n\nYour Selection is: ";
            continue;
        }
        cout << "\nSorry, wrong selection. Please try again:\n";
        cout << "\n1. Defend yourself\n2. Run towards Cornucopia\n3. Hide in nearby bushes\n4. Check Inventory\n\nYour Selection is: ";
        cin.clear();
        cin.ignore(123, '\n');
    }

    switch (selection) {
        case 1 : {
            if (!if_dead(user.get_df(), 20)) {
                sleep(2); cout << "\nYou successfully defended your position from the muts, and hear crys far away from other tributes.\n";
                win();
            }
            else { dead("muts"); }
            break;
        }
        case 2 : {
            if (!if_dead(user.get_sp(), 20)) {
                sleep(2); cout << "\nYou successfully ran away from the muts, and hear crys far away from other tributes.\n";
                win();
            }
            else { dead("muts"); }
            break;
        }
        case 3 : {
            if (!if_dead(user.get_cf(), 20)) {
                sleep(2); cout << "\nYou successfully hid from the muts and was undetected, you hear crys far away from other tributes.\n";
                win();
            }
            else { dead("muts"); }
            break;
        }
    }
}

void win() {
    sleep(2); cout << "\nCongratulations! You have won the 74th Annual Hunger Games!\n\n";
}

void dead(string cod) {
    sleep(2); cout << "\nYou died from " << cod << ". Better luck next time!\n\n";
}