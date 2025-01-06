#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<algorithm>

using namespace std;
// This function displays the Instruction when the game starts
void displayInstructions()
{
    cout << setw(60) << "\x1b[33m--------------------------------- WELCOME !--------------------------------------\x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m________________________________________________________________________________ \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|                                                                              | \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|---------------------------This is a Text based RPG---------------------------| \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|               _____   _______              _____   _______                   | \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|              /  ___| |__   __|    /\\      |  __ \\ |__   __|                  | \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|              | |___     | |      /  \\     | |__) |   | |                     | \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|              \\____  \\   | |     /    \\    |  _  /    | |                     | \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|                ___| |   | |    / ____ \\   | | \\ \\    | |                     | \x1b[0m " << endl;
    cout << setw(60) << "\x1b[32m|               |_____/   |_|   /_/    \\_\\  |_|  \\_\\   |_|                     | \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|______________________________________________________________________________| \x1b[0m" << endl
         << endl;
    cout << setw(60) << "\x1b[33m________________________________________________________________________________\x1b[0m" << endl
         << endl;
    cout << setw(60) << "\x1b[33m                        Welcome to The DreamScape Voyage                         \x1b[0m " << endl;
    cout << setw(60) << "\x1b[33m________________________________________________________________________________\x1b[0m" << endl
         << endl;
    cout << setw(60) << "\n\n\x1b[33mGet ready to delve into the World of dreams where reality is just a figment of imagination\x1b[0m" << endl;
    cout << setw(60) << "\n \x1b[33m\t\t    Hello! I am Moripheo; your DreamScape Guide\x1b[0m" << endl;
    cout << setw(60) << "\n \x1b[33m\t      I'm sure you are as excited as I am, so let's get started.\x1b[0m" << endl
         << endl;

    cout << setw(10) << "\n \x1b[32m\t\t\t\tEnter 1 to continue\x1b[0m" << endl;
    string userInput="";
    cin>>userInput;
    while (true)
        {
            if (userInput=="1")
            {
                break;
            }
             cout << setw(10) << "\n \x1b[33m\t\t Enter 1 to continue\x1b[0m" << endl;
            cin >> setw(10) >> userInput;
        }

    system("cls");
    cout << setw(20) << "\x1b[33m\nWelcome, Dreamer!\nThe DreamScape is in peril. Dark forces threaten its existence, all thanks to the malevolent MANAGMA."
    "\nMANAGMA has broken your dreamscape into fragments. Gain as much XP as possible to restore those fragmented dreams and maintain balance."
    "\nYour mission? Embark on a thrilling journey through battles, challenges, and confront MANAGMA in an epic showdown in order to gain XP."
    "\nBrace yourself for an adventure filled with danger and excitement. \x1b[0m" << endl;
    


         cout<< endl;
    cout << setw(20) << "\x1b[35m***************************************************************************\x1b[0m" << endl;
    cout << setw(20) << "\x1b[37m                           GOOD LUCK BRAVE SOUL!!                          \x1b[0m" << endl;
    cout << setw(20) << "\x1b[35m***************************************************************************\x1b[0m" << endl
         << endl;
}

void dialogue0()
{
    cout<< setw(20) <<"\x1b[33m\n\nYou wake up in a dark forest. Trees surround you from all sides. you see a small path ahead of you.";
    cout<< setw(20) <<"\nYou follow the path and see a sword in front of you.\x1b[0m";
    cout<< setw(20) <<"\x1b[34m\n\n1) Pick up the sword \t2) move ahead without the sword\n\x1b[0m";
}

void choice1a()
{
    cout<<"\n\n+12 attack\n";
    cout<<"\x1b[32mYou pick up the sword and move forward. You see a cave in front of you."
    "\nYou enter the cave and see a bear, and he looks hungry."
    "\nYou prepare yourself and put your sword up.\n\x1b[0m";
}
void choice1b()
{
    cout<<setw(30)<<"\x1b[33mYou move forward without the sword. You see a cave in front of you."
    "\nYou enter the cave and see a bear. The bear looks hungry."
    "\nBad luck for you. Looks like you should have picked up the sword the game throwed at you in the beginning."
    "\nThe bear attacks you. You are dead before the battle could even begin.\n\x1b[0m";
}
void end(int totalXp)
{   
    
            cout<<setw(20)<<"\n\nYou gained 0 Xp"<<endl;
            cout<<setw(20)<<"       Total Xp: "<<totalXp<<"\x1b[0m\n\n"<<endl;
    
    cout<<setw(60) << "\x1b[37m===========================Game Over====================================\x1b[0m"<<endl;
}
void line()
{
    cout<<setw(60)<<"\x1b[37m--------------------------------------------------------------------------------\x1b[0m"<<endl;
}

int attack(int attack1, int z)        // generates random attack value
{
    int y; 
    srand(time(0));
    y = rand() % 11 + (attack1 - z);
    return y;

}
int defense(int enemy_attack)          // generated defense value
{
    int y = attack(enemy_attack, 0);
    if(y%2 == 0)
    {
        return 0;
    }
    else if (y%2 > 0)
    {
        return y;
    }
}
// NORMAL FIGHT FUNCTION
int fight(string player_name, string enemy_name, int player_health, int enemy_health, int player_attack, int enemy_attack)
{  
    cout<<endl<<player_name<<"'s health: "<<player_health<<endl;
    cout<<enemy_name<<" health: "<<enemy_health<<endl<<endl;
    while(player_health>0 && enemy_health>0)
        {
            int choice;
            cout<<setw(10)<<"\x1b[33m[1)attack 2) defend]\n\n\x1b[0m";
            cin>>choice;
            if(choice == 1)                                                           // attack
                {   int x,y;
                    x = attack(player_attack, 5);
                    y = attack(enemy_attack, 6);

                    cout<<"\x1b[31mYou attacked the "<<enemy_name<<"\x1b[0m";
                    enemy_health = enemy_health - x;
                    cout<< "\x1b[31m\n" <<player_name<<" dealt "<<x<<" damage to "<<enemy_name<<"\x1b[0m"<<endl;
                    
                    if(enemy_health>0 && player_health>0)
                    {
                        player_health = player_health - y ;
                        cout<<"\x1b[32m"<<enemy_name<<"'s health: "<< enemy_health<<"\x1b[0m"<<endl;
                        cout<<"\x1b[32m"<<enemy_name<<" hit you for "<<y<<" damage"<<"\x1b[0m"<<endl;
                        if(player_health>0)
                        {
                            cout<<"\x1b[32m"<<player_name<<"'s health: "<<player_health<<"\x1b[0m"<<endl;
                        }
                        else
                        {
                            cout<<"\x1b[31m"<<"You lost"<<"\x1b[0m"<<endl;
                            return 0;
                        }
                    }
                    else if(enemy_health<=0 && player_health>0)
                    {
                        cout<<"\x1b[33m"<<player_name<<" killed the "<<enemy_name<<"\x1b[0m"<<endl;
                        return 1;

                    }
                    else if(enemy_health>0 && player_health<=0)
                    {
                        cout<<"YOU LOST"<<endl;
                        return 0;
                    }                   
                } 
            else if (choice == 2)                                                      // defense
                {
                    int def;
                    def = defense(enemy_attack);
                    if(def == 0)                                                    //successful defense
                    {
                        int dam = attack(player_attack, 0); 
                        dam = dam / 2;
                        cout<<"\x1b[31m"<<player_name<<" defended successfully\n";
                        cout<<enemy_name<<" took "<< dam <<" damage\n\x1b[0m";                       
                        cout<<"\x1b[32m"<<player_name<<"'s health: "<<player_health<<endl;
                        enemy_health = enemy_health -  dam;
                        cout<<enemy_name<<"'s health: "<<enemy_health<<"\x1b[0m"<<endl;
                    }
                    else if(def > 0)                                               // unsuccessful defense
                    {
                        player_health = player_health - (def / 2);
                        cout<<"\x1b[31m"<<player_name<<" tried to defend unsuccessfully\n";
                        cout<<enemy_name<<" hit "<<player_name<<" for "<<(def / 2)<<" damage\n\x1b[0m";
                        if(player_health>0)
                        {cout<<"\x1b[31m"<<player_name<<"'s health: "<<player_health<<endl<<"\x1b[0m";}
                        else {cout<<"You lost."; return 0;}
                        cout<<"\x1b[31m"<<enemy_name<<"'s health: "<<enemy_health<<endl<<"\x1b[0m";  
                    }                
                }
            else
            {
                cout<<"Incorrect input.\n";
            }
        }  
    if (player_health <= 0)                              // returns 0 or 1 depending on player health
    {
        return 0;
    }
    else if (player_health>0)
    {
        return 1; 
    }
    
}
// BOSS FIGHT FUNCTION
int bossfight(string player_name, string enemy_name, int player_health, int enemy_health, int player_attack, int enemy_attack, int special)
{  
    cout<<player_name<<"'s health: "<<player_health<<endl;
    cout<<enemy_name<<" health: "<<enemy_health<<endl;
    while(player_health>0 && enemy_health>0)
        {
            
            int choice;
            cout<<"\n\n\xb1[33m[1)attack\t 2) defend \t3) special power("<<special<<")]\n\x1b[0m";
            cin>>choice;
            if(choice == 1)                                                           // attack
                {   int x,y;
                    x = attack(player_attack, 5);
                    y = attack(enemy_attack, 6);

                    cout<<"\n\n\xb1[34mYou attacked the "<<enemy_name;
                    enemy_health = enemy_health - x;
                    cout<< "\n" <<player_name<<" dealt "<<x<<" damage to "<<enemy_name<<endl<<"\xb1[0m";
                    
                    if(enemy_health>0 && player_health>0)
                    {
                        player_health = player_health - y ;
                        cout<<setw(10)<<"\n\x1b[33m"<<enemy_name<<"'s health: "<< enemy_health<<endl;
                        cout<<setw(10)<<enemy_name<<" hit you for "<<y<<" damage\n\x1b[0m"<<endl;
                        if(player_health>0)
                        {
                            cout<<setw(10)<<"\n\x1b[33m"<<player_name<<"'s health: "<<player_health<<endl<<"\x1b[0m";
                        }
                        else
                        {
                            cout<<setw(10)<<"\n\x1b[33mYou lost!\n\x1b[0m"<<endl;
                            return 0;
                        }
                    }
                    else if(enemy_health<=0 && player_health>0)
                    {
                        cout<<setw(10)<<"\n\x1b[33m"<<player_name<<" killed the "<<enemy_name<<endl<<"\n\x1b[0m";
                        return 1;

                    }
                    else if(enemy_health>0 && player_health<=0)
                    {
                        cout<<setw(10)<<"\n\x1b[31mYOU LOST!\n\x1b[0m"<<endl;
                        return 0;
                    }                   
                } 
            else if (choice == 2)                                                      // defense
                {
                    int def;
                    def = defense(enemy_attack);
                    if(def == 0)                                                    //successful defense
                    {
                        int dam = attack(player_attack, 0); 
                        dam = dam / 2;
                        cout<<setw(10)<<"\n\x1b[34m"<<player_name<<" defended successfully\n";
                        cout<<setw(10)<<enemy_name<<" took "<< dam <<" damage\n\x1b[0m";                       
                        cout<<setw(10)<<"\n\x1b[32m"<<player_name<<"'s health: "<<player_health<<endl;
                        enemy_health = enemy_health -  dam;
                        cout<<setw(10)<<enemy_name<<"'s health: "<<enemy_health<<endl<<"\x1b[0m";
                    }
                    else if(def > 0)                                               // unsuccessful defense
                    {
                        player_health = player_health - (def / 2);
                        cout<<setw(10)<<"\n\x1b[34m"<<player_name<<" tried to defend unsuccessfully\n";
                        cout<<setw(10)<<enemy_name<<" hit "<<player_name<<" for "<<(def / 2)<<" damage\n\x1b[0m";
                        if(player_health>0)
                        {cout<<setw(10)<<"\n\x1b[33m"<<player_name<<"'s health: "<<player_health<<endl<<"\n\x1b[0m";}
                        else {cout<<setw(10)<<"You lost."; return 0;}
                        cout<<setw(10)<<"\n\x1b[33m"<<enemy_name<<"'s health: "<<enemy_health<<endl<<"\n\x1b[0m";  
                        
                    }                
                }
            else if(choice==3)
                {
                    if(special !=0)
                    {
                    int x = player_health*0.10;
                    player_health=x+player_health;
                    cout<<setw(10)<<"\x1b[33mYou used special power."<<endl;
                    cout<<setw(10)<<player_name<<"'s health: "<<player_health<<endl<<"\x1b[0m";
                    x = attack(player_attack,7);
                    enemy_health = enemy_health - x;
                    cout<<setw(10)<<"\x1b[35mYou dealt "<<x<<" damage to"<<enemy_name<<endl;
                    cout<<setw(10)<<enemy_name<<"'s health: "<<enemy_health<<endl<<"\x1b[0m";
                    special --;
                    }
                    else{cout<<setw(10)<<"\x1b[31mYOU HAVE NO SPECIAL POWERS REMAINING\x1b[0m"<<endl;}
                }
            else
                {
                    cout<<"Incorrect input.\n";
                }
        }  
    if (player_health <= 0)                              // returns 0 or 1 depending on player health
    {
        return 0;
    }
    else if (player_health>0)
    {
        return 1; 
    }
    
}
bool quizFileRead(string fileName, vector<string> &vecOfStrs) // to store the contents of non-empty lines of .txt files in a string 'vecOfStrs'
{
    ifstream in(fileName.c_str());
    // Checks if the file can be opened
    if (!in) // if not able to open; display an error message using 'cerr' and return false
    {
        cerr << "Cannot open the File : " << fileName << endl;
        return false;
    }
    string str;
    // Read the next line from File untill it reaches the end.
    while (getline(in, str))
    {
        // Fetch the contents of the non-empty (length>0) lines and store it in vector
        if (str.size() > 0)
            vecOfStrs.push_back(str);
    }
    // once data is fetched, close the file
    in.close();
    return true;
}

void quizDisplayQuestionAndOptions(string options, string questions)
{
    cout << setw(10) << questions << endl;
    cout << setw(10) << options << endl;
}

void quizDisplayOnEveryIteration()
{
    cout << setw(10) << "\n \x1b[36;43m Do you want to continue playing the game? (yes/no)\x1b[0m" << endl;
}

void quizDisplayGameOverMessage(int Xp)
{
    cout << setw(10) << "Your current Xp is: " << Xp << endl;
}

void quizMoripheosHelp(string moripheosHelpArr[], int &moripheosHelpChances)
{
    if (moripheosHelpChances > 0)
    {
        srand(time(0));
        int random_guess = rand() % 3 + 1;
        cout << setw(20) << "\x1b[33m  \n  So you have chosen to ask Moripheo for the answer. \n\n \x1b[31mBUT BEWARE!!!\n Moripheo is your dream guide he may also be as clueless as you.\x1b[0m" << endl;
        cout << setw(20) << "\x1b[32m  \n Anyways, Moripheo thinks that " << moripheosHelpArr[random_guess] << " is the correct answer go ahead test your luck. \x1b[0m" << endl;
        cout << setw(20) << " \x1b[33m \nWith this, you have used one of the Moripheos help \x1b[0m" << endl;
        moripheosHelpChances--;
    }
    else
    {
        cout << setw(5) << "\n\n \x1b[33mSorry, but you have already used all help chances\x1b[0m";
        cout << setw(5) << " \n\x1b[33m  Try to answer the question on your own now \x1b[0m" << endl;
    }
}

bool quizAnswerVerification(string usersAnswer, string correctAnswer)
{
    if (usersAnswer == correctAnswer)
        return true;
    else
        return false;
}

void bonusRound(string bonusQuestion, string bonusOptions)
{
    cout << setw(10) << "\n\x1b[44m -------------------- BONUS ROUND --------------------\x1b[0m" << endl;
    cout << setw(10) << "\x1b[33m\n Wow! You maintained a streak of 4 correct answers \n You deserve an oppurtunity to increase your Xp by \x1b[32m150 points\n\n \x1b[0m";
    cout << setw(10) << bonusQuestion << endl;
    cout << setw(10) << bonusOptions << endl;
}

void quizAccomplishmentMsg(int Xp)
{
    cout << setw(5) << "\x1b[33m   Congratulations! You accomplished this round\x1b[33m Your total Xp is " << Xp << "  \x1b[0m" << endl;
}

void quizInstructions()
{
    cout << setw(100) << "\n\x1b[36;43m Congratulations! You've vanquished the formidable Bear, one of the monsters lurking in the DreamScape.\x1b[0m" << endl;
    cout << setw(60) << "\x1b[36;43m Welcome to your next thrilling challenge: Quiz Trivia! \x1b[0m" << endl;
    cout << setw(20) << "\n\x1b[33m Here are the rules for this game:\x1b[0m" << endl;
    cout << setw(20) << "\x1b[33m 1)You'll now face 6 questions\x1b[0m" << endl;
    cout << setw(60) << "\x1b[33m 2)Every correct answer will grant you valuable XP points\x1b[0m" << endl;
    cout << setw(60) << "\x1b[33m 3)Be cautious! For every wrong answer, you'll incur a penalty of -5 XP\x1b[0m" << endl;
    cout << setw(60) << "\x1b[33m 4)Get on a hot streak of 4 correct answers! You'll then earn an opportunity to\ngain a whopping 20 XP points by answering a bonus question (No penalties for incorrect answer)\x1b[0m" << endl;
    cout << setw(60) << "\x1b[33m 5)Feeling stuck? You have the lifeline to consult Moripheo twice, but use them wisely!\x1b[0m" << endl;
}
void quiz(int totalXp)                                                // QUIZ 
{
    quizInstructions();
    vector<string> vecOfQuestions;
    // fetch questions
    bool result = quizFileRead("questions1.txt", vecOfQuestions);

    vector<string> vecOfOptions;
    // Fetch options
    result = quizFileRead("options1.txt", vecOfOptions);

    vector<string> vecOfAnswers;
    quizFileRead("answers1.txt", vecOfAnswers);

    bool gameloop = true;
    bool answerVerification = false;

    string continueOpt = "";
    string moripheosHelp = "";

    int Xp = totalXp;
    int lives = 2;
    int moripheosHelpChances = 2;
    int iteration = 0;
    int streak = 0;

    char endingOpt;
    // xp array
    int XpArr[6] = {15, 15, 15, 15, 15, 15};
    string moripheosHelpArr[4] = {"a", "b", "c", "d"};
    // quiz loop
    while (gameloop)
    {
        quizDisplayOnEveryIteration();
        cin >> setw(10) >> continueOpt;
        system("cls");
        if (continueOpt == "no")
        {
            quizDisplayGameOverMessage(Xp);
            break;
        }

        quizDisplayQuestionAndOptions(vecOfOptions[iteration], vecOfQuestions[iteration]);

        // Ask if you want to take Lifeline
        cout << setw(10) << "\x1b[32m\n Do you want to use Moripheo's help? \n\n \x1b[0m";
        cout << "\x1b[33mpress 1 to use help \n press 2 to continue without help. \n\n \x1b[0m" << endl;
        cin >> setw(10) >> moripheosHelp;
        if (moripheosHelp == " " && moripheosHelp != "2")
        {
            cout << setw(10) << "\x1b[33mincorrect input, choose again\x1b[0m" << endl;
            cin >> setw(10) >> moripheosHelp;
        }
        if (moripheosHelp == "1")
        {
            quizMoripheosHelp(moripheosHelpArr, moripheosHelpChances);
        }

        cout << setw(10) << "\x1b[33m \n Answer: \x1b[0m" << endl;
        string answer = "";
        cin >> setw(10) >> answer;

        while (true)
        {
            if (answer == "a" || answer == "b" || answer == "c" || answer == "d")
            {
                break;
            }
            cout << setw(10) << "\x1b[33m \n Please enter correct option to proceed with the game!\x1b[0m" << endl;
            cin >> setw(10) >> answer;
        }

        answerVerification = quizAnswerVerification(answer, vecOfAnswers[iteration]);
        if (answerVerification)
        {

            Xp += XpArr[iteration];
            system("cls");
            cout << setw(10) << " \n\n\x1b[33m Congrats!\nYour answer is correct; you'll gain +\x1b[32m" << XpArr[iteration] << " \x1b[0m \x1b[33mpoints.)\x1b[0m " << endl;
            cout << setw(10) << "\n \x1b[33m Total Xp: \x1b[32m " << Xp << endl;
            streak += 1;
            // bonus question
            if (streak == 4)
            {

                bonusRound(vecOfQuestions[6], vecOfOptions[6]);

                cout << setw(10) << "\x1b[33m Answer: \x1b[0m" << endl;
                string answer;
                cin >> setw(30) >> answer;
                answerVerification = quizAnswerVerification(answer, vecOfAnswers[6]);

                if (answerVerification)
                {

                    Xp += 20;
                    cout << setw(10) << " \n\n\x1b[33mCongrats you got this one! \n Your bonus of 20 Xp points is added\x1b[32m \x1b[0m\x1b[33mfor this right answer) \x1b[0m " << endl;
                    cout << setw(10) << "\n\x1b[33m  Total Xp: \x1b[0m\x1b[32m" << Xp << endl;
                }
                else
                {
                    system("cls");
                    cout << setw(10) << " \x1b[31m !WRONG ANSWER! \x1b[0m" << endl;
                }
            }
        }
        else
        {
            cout << setw(5) << "\n\x1b[37m ---------------------------\x1b[0m\n\n \x1b[31m  !Wrong answer! \n\x1b[0m ";
            streak = 0;
            lives--;
            if (lives == 0)
            {
                cout << setw(10) << "\x1b[31m \n Sorry! You ran out of lives \n\x1b[0m ";
                quizDisplayGameOverMessage(Xp);
                break;
            }
            else
                cout << setw(10) << "\x1b[31m You have " << lives << " live/s left\x1b[0m " << endl;
            Xp -= 5;
        }

        iteration++;
        // ends quiz
        if (iteration == 6)
        {
            quizAccomplishmentMsg(Xp);
            cout << "\n\t \x1b[33m-------------------QuizTrivia End!-------------------" << endl;
            cout << setw(10) << "You have reached the end of this round!\n \n Your total Xp is \x1b[32m" << Xp << endl;
            return;
        }
    }

    if (Xp == 0)
    {
        cout << "\n \x1b[33m Oh no! Your Xp is 0 \n Win other challenges to gain Xp.\x1b[0m ";
    }
    else
    {
        cout << "\n\t \x1b[33m-------------------QuizTrivia End!-------------------" << endl;
        cout << setw(10) << "You have reached the end of this round!\n \n Your total Xp is \x1b[32m" << Xp << endl;
    }
}
// anagram puzzle
void anagramGame(int totalXp) 
{
    srand(time(0));
    cout <<setw(60) <<"\x1b[35m\nWhen walking down the jungle, You hear some rustling in the bushes. You feel some roots grab your feet.";
    cout << setw(60) <<"\nThey are going to drag you into the depths of the jungle!!!";
    cout << setw(60) <<"\nYou try to untangle them but they are just holding on too tight. You see some glowing words appear in the sky that read:\x1b[0m";
    cout << setw(60) <<"\n\n\t\t\x1b[44mThrough the vines and shadows cast, a puzzle holds you firm and fast, Decipher the anagram, break the grasp, or in the jungle, forever last.\n\n\x1b[0m";
    
    string userGuess;
    string words[5] = {"forbidden", "mysterious", "enchanted", "uncharted", "warrior"};

    int randomIndex = rand() % 5;
    string selectedWord = words[randomIndex];

    string anagram = selectedWord;
    random_shuffle(anagram.begin(), anagram.end());

    cout << setw(20) << "\x1b[32m\n\n Anagram: " << anagram;
    if(randomIndex==0)
    {
        cout << setw(60) << "\x1b[35m   (Hint: Actions not allowed; against the rules) \n\x1b[0m" << endl;
    }
    else if(randomIndex==1)
    {
        cout << setw(60) << "\x1b[35m   (Hint: Full of secrets; puzzling and enigmatic) \n\x1b[0m" << endl;
    }
    else if(randomIndex==2)
    {
        cout << setw(60) << "\x1b[35m   (Hint: Magical and bewitched; charmed by sorcery) \n\x1b[0m" << endl;
    }
    else if(randomIndex==3)
    {
        cout << setw(60) << "\x1b[35m   (Hint: Unknown territory; unexplored and undiscovered) \n\x1b[0m" << endl;
    }
    else if(randomIndex==4)
    {
        cout << setw(60) << "\x1b[35m   (Hint: A brave fighter; skilled in combat and valor) \n\x1b[0m" << endl;
    }

  for (int chances = 0; chances < 3; chances++) 
   {
        string userGuess;
        cout << setw(10 )<< "\x1b[33m(Chance " << chances + 1 << "/3): \x1b[0m";
        cin >> setw(10) >> userGuess;

        transform(userGuess.begin(), userGuess.end(), userGuess.begin(), ::tolower); //converts the user input to lower case for case insensitive comparison

        if (userGuess == selectedWord && chances==0) 
        {
            cout <<setw(60) << "\x1b[34m\n\n************Wohooo! You solved the anagram************ \n\n\x1b[0m" << endl;
            cout<<setw(20)<<"\n\nYou gained 80 Xp"<<endl;
            totalXp += 80;  // Increment total experience points
            cout << setw(20) << "       Total Xp: " << totalXp << "\x1b[0m\n\n" << endl;
            return;
        } 
        else if (userGuess == selectedWord && chances==1) 
        {
            cout <<setw(60) << "\x1b[34m\n\n************Wohooo! You solved the anagram************ \n\n\x1b[0m" << endl;
            cout<<setw(20)<<"\n\nYou gained 60 Xp"<<endl;
            totalXp += 60;  // Increment total experience points
            cout << setw(20) << "       Total Xp: " << totalXp << "\x1b[0m\n\n" << endl;
            return;
        } 
        if (userGuess == selectedWord && chances==2) 
        {
            cout <<setw(60) << "\x1b[34m\n\n************Wohooo! You solved the anagram************ \n\n\x1b[0m" << endl;
            cout<<setw(20)<<"\n\nYou gained 30 Xp"<<endl;
            totalXp += 30;  // Increment total experience points
            cout << setw(20) << "       Total Xp: " << totalXp << "\x1b[0m\n\n" << endl;
            return;
        } 
        else {
            cout <<setw(60) << "\x1b[31m\n\n Ohh no! Incorrect:) \n\n\x1b[0m" << endl;
        }
        
    }

   { cout << setw(60) << "\x1b[31m\n\nSorry, you couldn't guess the word. The correct word was: \n\n\x1b[0m" << selectedWord << endl;
            cout<<setw(20)<<"\n\nYou gained 0 Xp"<<endl;
            cout << setw(20) << "       Total Xp: " << totalXp << "\x1b[0m\n\n" << endl;
   }
}

int main()
{   system("cls");
    cout << setw(40) << "\n \x1b[36mProject by Group Number 3 (Binary Bandits)\n"
                     "\n Group Members:\n\n 1) Affan Khalid(27100104)\t\t2) M.Nauman Asghar (26100388)\t\t3) M. Rafay Naseem (27100434)\x1b[0m" << endl;
    cout << setw(40) << "\n\n \x1b[32mEnter 1 to Acknowledge\x1b[0m" << endl;
    line();line();

    string acknowlegment="";
    cin>>acknowlegment;
    while (true)
        {
            if (acknowlegment=="1")
            {
                break;
            }
             cout << setw(10) << "\n \x1b[33m\t\t Enter 1 to continue\x1b[0m" << endl;
            cin >> setw(10) >> acknowlegment;
        }
    system("cls");
    int totalXp=100;
    system("cls");
    int Xp = 100; //initial Xp
    string name;           // name of the player
    int type, player_health, player_attack, defense;              
    displayInstructions();
    cout << "ENTER YOUR FIRST NAME: ";
    cin>>name;
    dialogue0();
    int choice1;
    cin>>choice1;
    
    if(choice1 == 1)                // game continues if user chooses 1                 
    {
        string bear = "Bear";
        int bear_health = 65;
        int bear_attack = 10;
        player_health = 70;
        player_attack = 12;
        choice1a();
        
        int resultfight1 = fight(name, bear, player_health, bear_health, player_attack, bear_attack);    // bear fight

        if (resultfight1 == 1)                                                    // if u win bear fight
        {
            cout<<setw(20)<<"\n\n\x1b[44m---------->You won<----------\x1b[0m"<<endl;
            cout<<setw(20)<<"\x1b[32mYou gained 20 hp."<<endl;
            cout<<setw(20)<<"Total health: "<<player_health + 20<<endl;
            cout<<setw(20)<<"You gained 5 attack power."<<endl;
            cout<<setw(20)<<"       Total attack: "<<player_attack+5<<"\x1b[0m"<<endl;
            line();
            cout<<setw(20)<<"\n\nYou gained 30 Xp"<<endl;
            totalXp += 30;  // Increment total experience points
            cout << setw(20) << "       Total Xp: " << totalXp << "\x1b[0m\n\n" << endl;

            line();
            player_health = 90;
            player_attack= 17;
            //DIALOGUE//
            int choice2=0;
            cout<<setw(20)<<"\x1b[34m \nYou move ahead and see 2 paths again. One path leads to a big dirty castle. The other path leads to an old temple. What is your choice?\n";
            cout<<setw(20)<<"\x1b[34m[1) move towards castle \t 2) move towards temple]\n\x1b[0m";
            cout<<"\x1b[34mYour choice: \x1b[0m";
            cin>>choice2;                                           // choice 2
    
            if(choice2==1)                                         // path 1
            {
                cout<<"\x1b[31mYou start to move towards the castle. As you get closer you see the huge castle gates in front of you. You hear the noise of a horse. You move ahead and see a knight in black broken armour sitting on a horse."
                     "\nThe knight lunges at you suddenly, but you dodge out of the way. Not quite the knight in shining armour that you were expecting.\n";
                cout<<"You get ready to fight.\x1b[0m\n\n";
                line();
                // knight fight
                string knight = "knight";
                int knight_attack = 14;
                int knight_health = 110;
                int resultknight = fight(name,knight, player_health,knight_health,player_attack,knight_attack);

                if(resultknight==1)                                      // if u win knight fight
                {
                    player_health = 110;
                    player_attack= 22;
                    cout<<setw(30)<<"\x1b[44m!!!!!!!!!!You won!!!!!!!!!!.\n";
                    cout<<setw(30)<<"You gained 20 hp."<<endl;
                    cout<<setw(30)<<"Total health: "<<player_health<<endl;
                    cout<<setw(30)<<"You gained 5 attack power."<<endl;
                    cout<<setw(30)<<"Total attack: "<<player_attack<<endl<<"\x1b[0m";
                    line();
                    line();
                    cout<<setw(20)<<"\n\nYou gained 40 Xp"<<endl;
                    totalXp+=40;
                    cout<<setw(20)<<"       Total Xp: "<<totalXp<<"\x1b[0m\n\n"<<endl;
                    line();
                    cout<<setw(60)<<"\x1b[33mYou move ahead. You are almost there. One final challenge awaits you before you face Managma himself.\n";
                    cout<<setw(30)<<"You see a jungle in front of you. You enter the jungle.\x1b[0m";
                    cout<<setw(10)<<"\x1b[33m Enter 1 to continue\n\x1b[0";
                    int var;
                    cin>>var;
                    if(var==1)
                    {
                        system("cls");
                    }
                    // ANAGRAM PUZZLE
                    anagramGame(totalXp);
                    line();
                    cout<<setw(30)<<"\n\n\x1b[34mYour long journey is almost over. Managma himself awaits you in his lair."<<endl;
                    cout<<setw(30)<<"You enter the lair. Managma is sitting on his throne in front of you. You challenge him to a fight.\x1b[0m"<<endl;
                    int special = 0;
                    // calculates number of special attacks user has
                    if(totalXp<=100)
                    {
                        special = 2;
                    }
                    else{special = 4;}
                    // final boss fight
                    int boss_health = 160;
                    int boss_attack= 25;
                    int resultboss = bossfight(name, "Managma", player_health,boss_health,player_attack,boss_attack,special);
                    if(resultboss ==1)
                    {
                        cout<<setw(30)<<"\x1b[33mYou defeated MANAGMA. Congratulations, You have won the game.\x1b[0m"<<endl;
                    }
                    else if(resultboss==0)
                    {
                        cout<<setw(10)<<"\x1b[31mYou lost.\x1b[0m"<<endl;
                        end(totalXp);
                    }
                }
                else if(resultknight==0)                        // if u lose bear fight
                {
                    end(totalXp);
                }
            }
            else if(choice2==2)                                         // PATH 2
            {
                cout<<setw(60)<<"\n\n\x1b[34mYou move to towards the temple. As you get closer, you see an old man sitting outside. The man looks harmless.\n";
                cout<<setw(60)<<"You ask the man about the temple. He tells you that his name is AGAKAI and that the temple belongs to him. You tell him to let him pass through the temple.\n";
                cout<<setw(60)<<"AGAKAI agrees, but on the condition that you take part in a quiz. If u pass, he will let you through.\n\x1b[0m";
                cout<<setw(10)<<"\n\x1b[33mPress 1 to continue: \x1b[0m";
                int temp0;
                cin>>temp0;
                if(temp0==1)
                {
                    // QUIZ GAME
                quiz(totalXp);
                }
                int temp;
                cout<<setw(20)<<"\x1b[33mPress 1 to continue: \x1b[0m";
                cin>>temp;
                if(temp==1)
                {
                cout<<"\x1b[33mYou move ahead. You are almost there. One final challenge awaits you before you face Managma himself.\n";
                cout<<"You see a cave in front of you. You enter the cave.\x1b[0m\n";
                // WITCH FIGHT
                string witch = "witch";
                int witch_attack = 14;
                int witch_health = 120;
                int resultWitch = fight(name,witch, player_health,witch_health,player_attack,witch_attack);
                if(resultWitch==1)                  //IF U WIN WITCH FIGHT                      
                {
                    player_health = 110;
                    player_attack= 22;
                    cout<<setw(20)<<"\x1b[44m\n\n----------WOHOOOO! You won----------\n";
                    cout<<setw(20)<<"You gained 20 hp."<<endl;
                    cout<<setw(20)<<"Total health: "<<player_health + 20<<endl;
                    cout<<setw(20)<<"You gained 5 attack power."<<endl;
                    cout<<setw(20)<<"Total attack: "<<player_attack+5<<endl<<"\x1b[0m\n\n";
                    line();
                    line();
                    cout<<setw(20)<<"\n\nYou gained 50 Xp"<<endl;
                    totalXp+=50;
                    cout<<setw(20)<<"       Total Xp: "<<totalXp<<"\x1b[0m\n\n"<<endl;
                    line();
                    cout<<setw(30)<<"\x1b[33mYour long journey is almost over. Managma himself awaits you in his lair."<<endl;
                    cout<<setw(30)<<"You enter the lair. Managma is sitting on his throne in front of you. You challenge him to a fight.\x1b[0m"<<endl;
                    int special = 0;
                    if(totalXp<=220)
                    {
                        special = 2;
                    }
                    else{special = 4;}
                    // FINAL BOSS FIGHT
                    int boss_health = 160;
                    int boss_attack= 25;
                    int resultboss = bossfight(name, "Managma", player_health,boss_health,player_attack,boss_attack,special);
                    if(resultboss ==1)
                    {
                        cout<<setw(10)<<"\n\n\x1b[44mYou defeated Managma. Congratulations, You have won the game.\n\x1b[0m"<<endl;
                        line();
                        cout<<setw(20)<<"\n\nYou gained 70 Xp"<<endl;
                        totalXp+=70;
                        cout<<setw(20)<<"       Total Xp: "<<totalXp<<"\x1b[0m\n\n"<<endl;
                        line();
                    }
                    else if(resultboss==0)
                    {
                        cout<<setw(10)<<"\x1b[31mOhh No!You lost.\x1b[0m"<<endl;
                        end(totalXp);
                    }
                }
                else if(resultWitch == 0)  // If u lose witch fight
                {
                    end(totalXp);
                }
                
                }
            }

        }
        else if (resultfight1 == 0)        // iF U LOSE BEAR FIGHT
        {
            cout<<"\x1b[31m You lost.\x1b[0m"<<endl;
            end(totalXp);
        }
    }
    else if(choice1 == 2)              // if u dont pick up sword in the beginning
    {
        choice1b();
        end(totalXp);
    }
    cout<<setw(10)<<"\x1b[44mYour Total Xp is: "<<totalXp<<" Congrats you came this far\x1b[0m";
    return 0;
}