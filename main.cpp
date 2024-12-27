/*
CP Semester Project
Project Title: Hangman
A Game in which the user has to guess a word within limited tries.
*/

// Importing Libraries
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <fstream>
using namespace std;

// Global Variables
int score=0;
char difficulty = 'E';
string name;
string user_message = "";
string white = "\033[37m";
string light_brown = "\033[93m";
string red = "\033[31m";
string green = "\033[32m";
string blue = "\033[36m";
bool is_user_message = false;
int rand_index = 0;

//Functions
void printHangmanAscii() {
    // Store each line of the ASCII art in strings
    cout<< "\n\n";
    string line1 = " _    _          _   _  _____ __  __          _   _ ";
    string line2 = "| |  | |   /\\   | \\ | |/ ____|  \\/  |   /\\   | \\ | |";
    string line3 = "| |__| |  /  \\  |  \\| | |  __| \\  / |  /  \\  |  \\| |";
    string line4 = "|  __  | / /\\ \\ | . ` | | |_ | |\\/| | / /\\ \\ | . ` |";
    string line5 = "| |  | |/ ____ \\| |\\  | |__| | |  | |/ ____ \\| |\\  |";
    string line6 = "|_|  |_/_/    \\_\\_| \\_|\\_____|_|  |_/_/    \\_\\_| \\_|";

    // Print the ASCII art
    cout << setw(88)<<line1 << endl;
    cout << setw(88)<<line2 << endl;
    cout << setw(88)<<line3 << endl;
    cout << setw(88)<<line4 << endl;
    cout << setw(88)<<line5 << endl;
    cout << setw(88)<<line6 << endl;
    cout<< endl;
}
void printgamefigure(int guesses){
    static int total = 6;
    string stages[7] = {
        // Initial empty state
        "\t\t\t\t\t\t        _________\n"
        "\t\t\t\t\t\t       |/        |\n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t     ==============",

        // Head added
        "\t\t\t\t\t\t        _________\n"
        "\t\t\t\t\t\t       |/        |\n"
        "\t\t\t\t\t\t       |        "+red+"(_)"+light_brown+"\n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t     ==============",

        // Head and neck
        "\t\t\t\t\t\t        _________\n"
        "\t\t\t\t\t\t       |/        |\n"
        "\t\t\t\t\t\t       |        "+red+"(_)"+light_brown+"\n"
        "\t\t\t\t\t\t       |         "+red+"|"+light_brown+"\n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t     ==============",

        // Head, neck, and one arm
        "\t\t\t\t\t\t        _________\n"
        "\t\t\t\t\t\t       |/        |\n"
        "\t\t\t\t\t\t       |        "+red+"(_)"+light_brown+"\n"
        "\t\t\t\t\t\t       |         "+red+"|"+light_brown+"\n"
        "\t\t\t\t\t\t       |       "+red+"/"+light_brown+"\n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t     ==============",

        // Head, neck, and both arms
        "\t\t\t\t\t\t        _________\n"
        "\t\t\t\t\t\t       |/        |\n"
        "\t\t\t\t\t\t       |        "+red+"(_)"+light_brown+"\n"
        "\t\t\t\t\t\t       |         "+red+"|"+light_brown+"\n"
        "\t\t\t\t\t\t       |       "+red+"/ | \\"+light_brown+"\n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t     ==============",

        // Head, neck, arms, and one leg
        "\t\t\t\t\t\t        _________\n"
        "\t\t\t\t\t\t       |/        |\n"
        "\t\t\t\t\t\t       |        "+red+"(_)"+light_brown+"\n"
        "\t\t\t\t\t\t       |         "+red+"|"+light_brown+"\n"
        "\t\t\t\t\t\t       |       "+red+"/ | \\"+light_brown+"\n"
        "\t\t\t\t\t\t       |        "+red+"/"+light_brown+"\n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t     ==============",

        // Complete figure (game over)
        "\t\t\t\t\t\t        _________\n"
        "\t\t\t\t\t\t       |/        |\n"
        "\t\t\t\t\t\t       |        "+red+"(_)"+light_brown+"\n"
        "\t\t\t\t\t\t       |         "+red+"|"+light_brown+"\n"
        "\t\t\t\t\t\t       |       "+red+"/ | \\"+light_brown+"\n"
        "\t\t\t\t\t\t       |        "+red+"/ \\"+light_brown+"\n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t       |         \n"
        "\t\t\t\t\t\t     =============="
    };

    if(guesses>=0 && guesses<=7){
        cout << stages[(total-guesses)] << endl;
    }
}
void printdifflevel(){
    // Current Difficulty Level
    if(difficulty=='M')
        cout <<"\n\n"<<setw(42)<< "Difficulty: Medium";
    else if(difficulty=='E')
        cout << "\n\n" <<setw(36)<< "Difficulty: "<< green <<"Easy" << light_brown;
    else if(difficulty=='H')
        cout << "\n\n" <<setw(36)<< "Difficulty: "<< red <<"Hard" << light_brown;
}
void printscore(){
    // Current Score
    cout << setw(52) << "Score: " << score << endl;
}
void printinstructions(){
        cout<<setw(39)<< "Instructions: "<< endl << endl;
        cout<< setw(96)<< "1.The Rule is to Guess the word by entering one letter at a time." << endl<<endl;
        cout<< setw(102)<< "2.The number of allowed guesses depends on the chosen difficulty level." << endl<<endl;
        cout<< setw(104)<< "3.Change the difficulty anytime from the main menu or at the end of game."<< endl<<endl;
        cout<< setw(90)<< "4.Hints are available in Easy and Medium difficulty levels." << endl<<endl;
        cout<< setw(72)<< "5.Hard difficulty does not include hints!"<< endl<<endl;
        cout<< setw(107)<< "6.Each wrong guess adds a part to the Hangman figure. Don't let it complete!"<< endl<<endl;
        cout<< setw(79)<< "7.Press '!' during the game to exit immediately."<< endl<<endl;
        cout<< setw(68)<< "Press s to return to main menu: ";
}
void loading_screen(string message,int k) {

    // Loading loop
    for(int i=1;i<10;i++){
        // Clear Screen

        for(int j=0;j<10;j+=k){
        system("cls");
        cout << message << i << j <<"%" << endl;
        Sleep(50);
        }

    }
}
void user_login(){
    system("cls");
    printHangmanAscii();
    string line1;
    bool not_name = false;
    cout << endl << endl << "\t\t\t\t\t\t  Enter Your name: ";
    cin >> name;

    ifstream fin;
    fin.open("users.txt");
    if(fin.is_open()){
        while(fin) {
            getline(fin,line1);

        if (line1 == name){
            user_message = "\t\t\t\t\tWelcome Back " + blue + name + light_brown + "! Let's play Hangman again!";
            not_name = false;
            fin.close();
            break;
        }
        else{
            user_message = "\t\t\t   Welcome to Hangman! " + blue + name + light_brown + " Get ready to guess letters and solve the puzzle!";
            not_name=true;

        }
        }
        fin.close();

        if(not_name==true){
            ofstream myfile("users.txt",ios_base::app);
            if(myfile.is_open())
            {
                myfile<< name << endl;
                myfile.close();
            }
            else cerr<<"Unable to open file";
        }
    }

}
string rword()
{
    string rw[] = {"apple", "river", "laugh", "market", "create", "basket", "dream", "whisper", "sunset", "travel",
        "light", "magic", "north", "ocean", "piano", "quiet", "river", "shelf", "train", "under", "water", "youth", "zebra", "alien", "brave", "candy", "dance", "eager", "flame",
        "garden", "storm", "rescue", "forest", "journey", "system", "pencil", "explore", "harvest", "shadow",
        "wheat", "yacht", "zone", "arrow", "birth", "cloud", "drift", "exile", "flair", "grind", "habit", "input", "jump", "knack", "lamp", "moon","orbit", "peace", "quiet",
        "expand", "canyon", "promise", "thunder", "compass", "library", "station", "pattern", "melody", "silence",
        "rock", "spark", "toxic","vigor", "whale", "yield", "album", "crane", "dust", "evade", "frame", "globe", "hinge", "ideal", "joke", "knee", "time",
        "reach", "uncle", "waste", "clear", "dare", "early", "feast", "haste", "index", "juice", "knead", "lunar", "march", "never", "ocean", "plum", "earthquake", "ridge", "stake", "tame", "uphill", "voice",
        "lantern", "texture", "emerald", "orchard", "seaside", "diamond", "painter", "teacher", "horizon", "courage",
        "kindness", "discover", "organize", "surprise", "remember", "translate", "celebrate", "motivate", "appreciate", "determine",
        "shelter", "picture", "soldier", "freedom", "village", "harmony", "rainbow", "waterfall", "landscape", "adventure",
        "simplify", "clarify", "accomplish", "encourage", "memorize", "transform", "brainstorm", "understand", "communicate", "recognize",
        "revolutionize", "synchronize", "prioritize", "integrate", "implement", "streamline","beach", "chair", "earth", "fight", "grape", "house", "joker", "knife",
        "giant", "honor", "image", "king", "love", "mouse", "night", "olive", "plant", "queen", "raise", "shout", "table", "urban", "delicious", "angel", "blast",
        "craft","equip", "frost", "glory", "heart", "inbox", "jewel", "kite", "lemon",  "metal", "novel", "onion", "plate", "quilt", "react", "smile", "tiger", "unite", "valor",
        "collaborate", "illustrate", "differentiate", "contribute", "manipulate", "demonstrate", "authenticate", "compromise", "summarize", "categorize",
        "mango", "noble","quota", "roast", "tempo", "upset", "vines", "cloak", "deal", "eagle", "float", "glance", "hand", "employ","kneel", "logic", "music","oasis", "plain",
        };
    int size1 = sizeof(rw)/sizeof(rw[0]);
    srand(time(0));
    int randindex = rand()% size1;
    rand_index = randindex;
    string randword = rw[randindex];
    return randword;
}
string get_hint(int randindex){
    string hint_arr[] = {
    "A fruit that's red or green", // apple
    "A flowing body of water", // river
    "A sound of joy", // laugh
    "A place to buy goods", // market
    "To bring something into existence", // create
    "A container to hold things", // basket
    "Something you see when you sleep", // dream
    "A soft, low sound", // whisper
    "The end of the day", // sunset
    "To go to different places", // travel
    "Opposite of dark", // light
    "Something mystical or enchanting", // magic
    "The opposite of south", // north
    "A vast body of saltwater", // ocean
    "A musical instrument with keys", // piano
    "Silent and peaceful", // quiet
    "Repeats in this list (hint: water flows here)", // river
    "A flat storage unit", // shelf
    "A mode of transport on tracks", // train
    "Opposite of over", // under
    "Covers most of the Earth's surface", // water
    "A time of life when you're young", // youth
    "A striped animal", // zebra
    "A creature from another planet", // alien
    "Showing courage", // brave
    "A sweet treat", // candy
    "A rhythmic movement", // dance
    "Full of enthusiasm", // eager
    "A small fire or passion", // flame
    "A place where plants grow", // garden
    "Heavy rain and wind", // storm
    "To save someone from danger", // rescue
    "A wooded area", // forest
    "A long trip or adventure", // journey
    "An organized framework", // system
    "A tool for writing or drawing", // pencil
    "To travel and discover", // explore
    "The season of gathering crops", // harvest
    "A dark area formed by blocking light", // shadow
    "A type of grain", // wheat
    "A luxurious boat", // yacht
    "An area or region", // zone
    "A pointed projectile", // arrow
    "The start of life", // birth
    "White fluffy things in the sky", // cloud
    "To float away aimlessly", // drift
    "To be sent away", // exile
    "A natural talent or style", // flair
    "To crush", // grind
    "A repeated action", // habit
    "Data entered into a system", // input
    "A sudden upward movement", // jump
    "A knack or skill", // knack
    "A portable light source", // lamp
    "Earth's natural satellite", // moon
    "A curved path around a planet", // orbit
    "A state of calm", // peace
    "Still and calm (repeats in this list)", // quiet
    "To stretch or grow wider", // expand
    "A deep valley", // canyon
    "A commitment or assurance", // promise
    "A loud rumbling sound", // thunder
    "A navigation tool", // compass
    "A collection of books", // library
    "A stop for trains", // station
    "A recurring design", // pattern
    "A tune or harmony", // melody
    "The absence of sound", // silence
    "A hard mineral or music genre", // rock
    "A small, bright burst", // spark
    "Harmful or poisonous", // toxic
    "Great energy or enthusiasm", // vigor
    "A large marine mammal", // whale
    "To produce or give", // yield
    "A collection of music or photos", // album
    "A large bird or a lifting machine", // crane
    "Fine particles of dirt", // dust
    "To avoid or escape", // evade
    "A border or edge", // frame
    "A spherical map of Earth", // globe
    "A movable joint or connection", // hinge
    "The perfect version of something", // ideal
    "A funny story or remark", // joke
    "A joint in your leg", // knee
    "Keeps track of passing moments", // time
    "To stretch or extend", // reach
    "A male relative of your parents", // uncle
    "To discard or trash", // waste
    "Not cloudy or clean", // clear
    "To challenge or take a risk", // dare
    "Happening at the start", // early
    "A large meal or celebration", // feast
    "Quickness or urgency", // haste
    "A list or reference", // index
    "A sweet, liquid drink", // juice
    "To press or squeeze dough", // knead
    "Related to the moon", // lunar
    "A month of marching", // march
    "Opposite of always", // never
    "A body of saltwater (repeats in this list)", // ocean
    "A small, round fruit", // plum
    "A sudden shaking of the ground", // earthquake
    "A long, narrow hilltop", // ridge
    "To bet or risk something", // stake
    "Domesticated or under control", // tame
    "Ascending or sloping upwards", // uphill
    "The ability to make sound", // voice
    "A portable light source used at night", // lantern
    "The feel or appearance of a surface", // texture
    "A precious green gemstone", // emerald
    "A grove of fruit trees", // orchard
    "The area where land meets the ocean", // seaside
    "A valuable, shiny gem", // diamond
    "An artist who creates visual art", // painter
    "Someone who educates others", // teacher
    "The line where the earth meets the sky", // horizon
    "Bravery in the face of fear", // courage
    "The quality of being nice or considerate", // kindness
    "To find or uncover something new", // discover
    "To arrange or manage systematically", // organize
    "An unexpected event or reaction", // surprise
    "To recall something from the past", // remember
    "To convert one language into another", // translate
    "To honor or rejoice in something special", // celebrate
    "To inspire or drive someone forward", // motivate
    "To express gratitude for something", // appreciate
    "To decide firmly or resolve something", // determine
    "A place offering protection or refuge", // shelter
    "A visual representation or image", // picture
    "A person who serves in the military", // soldier
    "The state of being free", // freedom
    "A small community or settlement", // village
    "A pleasing combination of sounds or ideas", // harmony
    "A colorful arc seen after rain", // rainbow
    "A stream of water falling from a height", // waterfall
    "A scenic view of natural surroundings", // landscape
    "An exciting or unusual experience", // adventure
    "To make something simpler or easier to understand", // simplify
    "To make something clearer or easier to understand", // clarify
    "To achieve something successfully", // accomplish
    "To give support or confidence to someone", // encourage
    "To commit something to memory", // memorize
    "To change something drastically or entirely", // transform
    "To come up with ideas creatively", // brainstorm
    "To grasp the meaning or logic of something", // understand
    "To exchange ideas or information effectively", // communicate
    "To identify or acknowledge something", // recognize
    "To cause a major change or revolution in something", // revolutionize
    "To align things to work in harmony", // synchronize
    "To arrange tasks or items by importance", // prioritize
    "To combine different parts into a whole", // integrate
    "To put something into action", // implement
    "To improve efficiency or simplify a process", // streamline
    "A sandy or pebbly area near water", // beach
    "A piece of furniture for sitting", // chair
    "The planet we live on", // earth
    "A physical struggle or battle", // fight
    "A small, juicy fruit often purple or green", // grape
    "A building for living", // house
    "A funny or entertaining character", // joker
    "A sharp tool for cutting", // knife
    "A very large being or creature", // giant
    "Great respect or admiration", // honor
    "A visual representation or likeness", // image
    "A male ruler of a kingdom", // king
    "A deep affection for someone or something", // love
    "A small rodent or computer accessory", // mouse
    "The time of day when it's dark", // night
    "A small green fruit, often used for oil", // olive
    "A living organism that grows in soil", // plant
    "A female ruler or monarch", // queen
    "To lift or elevate something", // raise
    "To call out loudly", // shout
    "A piece of furniture with a flat surface", // table
    "Related to cities or towns", // urban
    "Pleasing to taste or smell", // delicious
    "A divine or spiritual being", // angel
    "A powerful explosion or sudden event", // blast
    "To create something skillfully", // craft
    "To supply with necessary items", // equip
    "A thin layer of ice or cold mist", // frost
    "Great honor or praise", // glory
    "The organ that pumps blood", // heart
    "A digital mailbox for receiving messages", // inbox
    "A precious stone or ornament", // jewel
    "A flying toy attached to a string", // kite
    "A sour yellow fruit", // lemon
    "A hard substance, often metallic", // metal
    "A fictional or long prose story", // novel
    "A vegetable with layers and a strong smell", // onion
    "A flat dish used for serving food", // plate
    "A bedspread made from stitched pieces of fabric", // quilt
    "To respond or act in return", // react
    "A facial expression showing happiness", // smile
    "A large wild cat with stripes", // tiger
    "To join or come together", // unite
    "Strength of mind in difficult situations", // valor
    "To work together as a team", // collaborate
    "To explain something with visuals or examples", // illustrate
    "To identify differences between items", // differentiate
    "To contribute or add to a cause", // contribute
    "To control or influence something skillfully", // manipulate
    "To show or explain something clearly", // demonstrate
    "To prove something is genuine or real", // authenticate
    "To reach an agreement by mutual concession", // compromise
    "To condense or explain briefly", // summarize
    "To arrange into categories or groups", // categorize
    "A tropical fruit with a sweet flavor", // mango
    "Having excellent character or qualities", // noble
    "A set or limit for something", // quota
    "To cook something over heat", // roast
    "The pace or rhythm of a song", // tempo
    "To feel disturbed or bothered", // upset
    "Climbing plants with long stems", // vines
    "A piece of clothing worn over other clothes", // cloak
    "An agreement or business arrangement", // deal
    "A large bird of prey", // eagle
    "To stay on the surface of water", // float
    "A quick look or peek", // glance
    "The part of the body at the end of the arm", // hand
    "To hire someone for a job", // employ
    "To lower the body on one knee", // kneel
    "Reasoning or sound judgment", // logic
    "Art formed from sounds and rhythms", // music
    "A fertile area in the desert with water", // oasis
    "A flat, open area of land", // plain
};
    return hint_arr[randindex];
}

// Main Function
int main() {
    //Declarations
    bool hasmain=false,inc_diff=false;
    string random_word;
    int user_input1;
    system("color 0E");

    user_login();
    system("cls");

    // Main Loop
    do{
        printHangmanAscii();
        if(is_user_message==false){
            cout << endl << user_message << endl;
            Sleep(2000);
            is_user_message=true;
        }
        // Edge case
        if(user_input1!='1' && user_input1!='2')
            if(hasmain==true)
                cout << endl <<setw(80)<< "Invalid Input! Press Enter to Try Again." << endl;

        // Main menu
        printdifflevel();
        printscore();
        cout <<endl<<setw(71)<< endl << "Press 1 to Play the game." <<endl<<setw(80)<< endl << "Press 2 to Change Difficulty Level" <<endl<<setw(74)<< endl << "Press 3 to view instructions" << endl<<setw(61)<<endl<< "Press 4 to exit"<<endl;
        user_input1 = getch();

        // Main Conditions
        switch(user_input1){
        // Play
        case '1':{
            // Loading Game
            loading_screen("Loading... ",4);

            start:
            // Initializing Game conditions
            system("cls");
            vector<char> inc_guesses = {};
            int inc_counter=0;
            char user_input2,user_input3;
            bool correct = false;
            int temp_score;
            int attempts = (difficulty=='E')? 6 : (difficulty=='M')? 5 : (difficulty=='H')? 3 : 5;
            random_word = rword();
            string random_word_copy = random_word;
            int word_length = random_word.length();
            char word_arr[word_length];
            for(int i=0;i<word_length;i++)
                word_arr[i] = '_';

            // Bug Handling
            if(word_length==0)
                goto start;

            // Game loop
            do{
                    system("cls");
                int counter=0;
                printHangmanAscii();

                // Displaying the number of guesses remaining
                 cout<< setw(46)<<"Number of Guesses: " << attempts;

                // Displaying incorrect guess
                cout << setw(45)<<" Incorrect Guesses: ";
                for(int i=0;i<inc_counter;i++){
                    cout << inc_guesses[i] << " ";
                }

                cout << endl << endl;

                  // Displaying Hangman Game Figure
                printgamefigure(attempts);

                cout << endl << endl;

                if(difficulty!='H'){
                    if(difficulty=='M' && attempts<=2){
                    cout << "\t\t\t\t\t  Hint: " << get_hint(rand_index) << endl;
                    } else if (difficulty=='E' && attempts<=4){
                    cout << "\t\t\t\t\t  Hint: " << get_hint(rand_index) << endl;
                    }
                }


                cout << "\t\t\t\t\t  Guess the Word: ";

                // Displaying the word array
                for(int i=0;i<word_length;i++){
                    cout << word_arr[i] << " ";
                }
                cout << " ";

                // User enters a character
                user_input2 = getch();

                // Exit condition
                if(user_input2=='!'){
                    goto ending;
                }

                // Checking the character if it is correct or not
                for(int i=0;i<word_length;i++){
                    if(user_input2==random_word[i]){
                            correct=true;
                            word_arr[i] = random_word[i];
                            random_word[i] = '_';
                    }
                }


                // Displaying result
                if(correct==true){
                    cout << endl << endl << endl << green <<setw(64)<< "Correct!" << light_brown << endl << endl;
                    temp_score+= 2 + attempts*(0.5);
                    Sleep(500);
                    //system("color 0F");

                } else {
                    cout << endl << endl << endl << red <<setw(75)<< "Wrong Guess! Please Try Again." << light_brown << endl << endl;
                    inc_guesses.push_back(user_input2);
                    inc_counter++;
                    attempts--;
                    Sleep(1000);
                    //system("color 0F");
                }

                // Victory condition
                 for(int i=0;i<word_length;i++){
                    if(random_word[i]!='_')
                        break;

                    counter++;
                 }

                 if(counter==word_length){
                    for(int i=0;i<word_length;i++){
                        if(i==0)
                            cout << "\t\t\t\t\t\t       ";
                        cout << word_arr[i];
                    }
                    cout << endl << endl;
                    cout <<setw(68)<< "You have won!" << endl << endl;
                    score+=temp_score;
                    score = (difficulty=='H')? score*3 : (difficulty=='M')? score*2 : score;
                    Sleep(3000);
                    cout <<setw(87)<< "Do you want to try again?(y/n) or change difficulty(e/m/h): ";
                    cin >> user_input3;

                    if(user_input3=='y')
                        goto start;

                    break;
                 }

                correct=false;
            }while(attempts>0);
            //losing condition
            if(attempts==0){
            system("cls");
            printHangmanAscii();
            printgamefigure(attempts);
            cout << endl<<setw(65)<<"Game Over.\n";
            cout << setw(60)<< "Word: " << random_word_copy << "\n\n";
            repeat1:
            Sleep(2000);
            cout <<setw(89)<< "Do you want to try again?(y/n) or change difficulty(e/m/h): ";
            cin >> user_input3;

            if(user_input3=='y')
                goto start;
            }

            if(user_input3=='e' || user_input3=='m' || user_input3=='h'){
                difficulty = (user_input3=='e')? 'E' : (user_input3=='m')? 'M' : (user_input3=='h')? 'H' : 'E';
                switch(difficulty){
                case 'E':
                    cout << endl <<setw(72)<< "Difficulty changed to Easy!" << endl << endl;
                    break;
                case 'M':
                    cout << endl <<setw(72)<< "Difficulty changed to Medium!" << endl << endl;
                    break;
                case 'H':
                    cout << endl <<setw(72)<< "Difficulty changed to Hard!" << endl << endl;
                    break;
                }

                goto repeat1;
            }

            if(user_input3!='n'){
                cout << endl <<setw(72)<< "Wrong Input! Please try again." << endl << endl;
                goto repeat1;
            }

            ending:
            loading_screen("Going back... ",6);
            break;}
        // Change Level
        case '2':
            char user_input2;
            do{
                system("cls");
                printHangmanAscii();

                if(inc_diff==true)
                    cout << endl <<setw(80)<< "Wrong difficulty level! Please try again." << endl;

                printdifflevel();
                cout << endl;

                cout << endl <<endl <<setw(75)<< "Press e for Easy Difficulty Level.\n" << endl << setw(77)<<"Press m for Medium Difficulty Level.\n" << endl << setw(75)<<"Press h for Hard Difficulty Level.\n" << endl<<setw(63)<< "Press r to Return Back." << endl;
                user_input2 = getch();

                // Setting Difficulty Level
                if(user_input2=='e'){
                    inc_diff=false;
                    difficulty='E';
                }
                else if(user_input2=='m'){
                    inc_diff=false;
                    difficulty='M';
                }
                else if(user_input2=='h'){
                    inc_diff=false;
                    difficulty='H';
                }
                else if(user_input2!='r')
                    inc_diff=true;

            }while(user_input2!='r');
            break;
        case '3':
              char user_input3;
              system("cls");
            do
            {
                printHangmanAscii(); cout<< endl << endl;
                printinstructions();
                user_input3 = getch();
                system("cls");

            }while(user_input3!='s');
            break;

        default:
            hasmain=true;
        }

        system("cls");
    }while(user_input1!='4');

    // Last Output
    printHangmanAscii();
    cout << endl << endl << setw(85)<<"Thanks for Playing! Please Come Again Anytime." << endl<<endl<<endl;
    return 0;
}
