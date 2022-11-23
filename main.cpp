#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void menu();

void clearScreen()
{
  system("clear");
}

string getRandomWord()
{
  string words[3] = {"abacaxi", "manga", "morango"};
  int randomIndex = rand() % 3;
  return words[randomIndex];
}

string getWordWithMask(string word)
{

  int count = 0;
  string wordWithMask;

  while (count < word.size())
  {
    wordWithMask += "_";
    count++;
  }

  return wordWithMask;
}

void showStatus(string wordWithMask, int remainingAttempts, string logLetter, string message)
{
  cout << message << endl;
  cout << "Word: " << wordWithMask << endl;
  cout << "Word Size: " << wordWithMask.size() << endl;
  cout << "Remaining attempts: " << remainingAttempts << endl;
  cout << "Log letters: " << logLetter << endl;
}

void gameAlone()
{
  string word = getRandomWord();
  int size = word.size();
  string wordWithMask = getWordWithMask(word);

  int attempts = 0, maxAttempts = 10, count = 0;
  int option;
  char letter;
  string logLetter;
  string message = "Welcome to the game!";
  string tryWord;
  bool letterAlreadyTyped = false;

  while (word != wordWithMask && maxAttempts - attempts > 0)
  {
    showStatus(wordWithMask, maxAttempts - attempts, logLetter, message);

    cout << "Type a letter (or type 1 for try to get the word right): ";
    cin >> letter;

    if (letter == '1')
    {
      cin >> tryWord;
      if (tryWord == word)
      {
        wordWithMask = tryWord;
      }
      else
      {
        attempts = maxAttempts;
      }
    }

    for (int i = 0; i < attempts; i++)
    {
      if (logLetter[i] == letter)
      {
        letterAlreadyTyped = true;
        message = "This letter already typed";
      }
      else
      {
        letterAlreadyTyped = false;
      }
    }

    if (letterAlreadyTyped == false)
    {
      logLetter += letter;

      for (count = 0; count < size; count++)
      {
        if (word[count] == letter)
        {
          message = "You got a letter right!";
          wordWithMask[count] = word[count];
        }
      }

      attempts++;
    }

    clearScreen();
  }

  if (word == wordWithMask)
  {
    cout << "Congratulations you won!! :)" << endl;
    cout << "You want restart?" << endl;
    cout << "1-Yes" << endl;
    cout << "2-No" << endl;
    cin >> option;

    if (option == 1)
    {
      menu();
    }
    else
    {
      cout << "See ya!";
    }
  }
  else
  {
    cout << "You looose! :(" << endl;
    cout << "You want restart?" << endl;
    cout << "1-Yes" << endl;
    cout << "2-No" << endl;
    cin >> option;
    if (option == 1)
    {
      menu();
    }
    else
    {
      cout << "See ya!";
    }
  }
}

void menu()
{
  int option = 0;

  while (option < 1 || option > 3)
  {
    clearScreen();
    cout << "Welcome to the game" << endl;
    cout << "1 - Play" << endl;
    cout << "2 - About" << endl;
    cout << "3 - Exit" << endl;
    cout << "Choose an option and press enter:" << endl;
    cin >> option;
    clearScreen();

    switch (option)
    {
    case 1:
      gameAlone();
      break;

    case 2:
      cout << "Game Informations:" << endl;
      cout << "Dev: Vinicius Dias, at 2022!\n"
           << endl;
      cout << "1 - Back" << endl;
      cout << "2 - Exit" << endl;
      cin >> option;
      if (option == 1)
      {
        menu();
      }
      break;

    default:
      cout << "See ya!";
      break;
    }
  }
}

int main()
{
  srand((unsigned)time(NULL));
  menu();

  return 0;
}