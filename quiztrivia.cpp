#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

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
    cout << setw(60) << "\n\x1b[36;43m Welldone You defeated the bear; it was one of the monsters of MANAGMA\x1b[0m" << endl;
    cout << setw(60) << "\x1b[36;43m Now I Welcome You to your next challenge: Quiz Trivia \x1b[0m" << endl;
    cout << setw(20) << "\n\x1b[33m Here are the rules for this game:\x1b[0m" << endl;
    cout << setw(20) << "\x1b[33m 1)you will be asked a total of 5 questions\x1b[0m" << endl;
    cout << setw(60) << "\x1b[33m 2)For each correct answer you will be rewarded 20 Xp points\x1b[0m" << endl;
    cout << setw(60) << "\x1b[33m 1)For every wrong answer there will a penealty of -5 in health\x1b[0m" << endl;
    cout << setw(60) << "\x1b[33m 1)you can use a lifeline to ask Moripheo but you can use it only 2 times\x1b[0m" << endl;
}

int main()
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

    int Xp = 0;
    int lives = 2;
    int moripheosHelpChances = 2;
    int iteration = 0;
    int streak = 0;

    char endingOpt;

    int XpArr[6] = {10, 20, 35, 55, 80, 110};
    string moripheosHelpArr[4] = {"a", "b", "c", "d"};

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

            if (streak == 4)
            {

                bonusRound(vecOfQuestions[6], vecOfOptions[6]);

                cout << setw(10) << "\x1b[33m Answer: \x1b[0m" << endl;
                string answer;
                cin >> setw(30) >> answer;
                answerVerification = quizAnswerVerification(answer, vecOfAnswers[6]);

                if (answerVerification)
                {

                    Xp += 150;
                    cout << setw(10) << " \n\n\x1b[33mCongrats you got this one! \n Your bonus of 150 Xp points is added\x1b[32m \x1b[0m\x1b[33mfor this right answer) \x1b[0m " << endl;
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
            Xp -= 30;
        }

        iteration++;
        if (iteration == 6)
            quizAccomplishmentMsg(Xp);
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
    
    return 0;
}