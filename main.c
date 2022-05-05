#include <stdio.h>
#include <stdlib.h>
#include "create_twitter.c"
#include "delete-user.c"
#include "follow-user.c"
#include "post-tweet.c"
#include "unfollow-user.c"
#include "next-user.c"
#include "news-feed.c"


void CloseTwitter(void);

int main() {//start of main
    int key = 0;
    twitter twitter_system;  //define the twitter_system

    create_twitter_system(&twitter_system); //create users

    int num = twitter_system.num_tweets = 0;

    //print all users
    for (int i =0; i < twitter_system.num_users - 1; i++) {
        user usr = twitter_system.users[i];
        //print initial profile of each user
        printf("User %i: %s; Followers: %d; Following: %d\n",i + 1, usr.username, usr.num_followers, usr.num_followers );
    }
    //display twitter description
    printf("\nTWITTER SYSTEM ===\n"
           "\t- Each user has a turn to perform any amount of function (see keys below)\n"
           "\t- When next-user() is activated, that user will end it's turn and move onto the next\n"
           "\t- When the last user is skipped, the twitter system will loop back to the first user\n"
           "\t- CloseTwitter() can be activated at any stage to stop the program\n");
    //display function keys to the users
    printf("\nFUNCTION KEYS ===\n"
           "\t- 0 = Move To Next User\n"
           "\t- 1 = Follow\n"
           "\t- 2 = Post Tweet\n"
           "\t- 3 = Get News Feed\n"
           "\t- 4 = Unfollow\n"
           "\t- 5 = Delete Account\n"
           "\t- 6 = Close Twitter\n");

    //iterate over each user and ask user to prompt a function
    for (int i =0; i < twitter_system.num_users - 1; i++) {
        user * usr = &twitter_system.users[i]; //user in current iteration

        printf("input a function key for <%s>", &usr -> username);
        scanf("%d", &key);

        //while the user is still in turn (0 = go to next user)
        while (key != 0) {
            if (key == 1) {
                int index;
                printf("Enter index of user that %s will follow: ", usr->username);
                scanf("%d", &index);
                user *b = &twitter_system.users[index]; //user that usr will follow
                follow(usr, b); //"usr will follow b"
            }
            else if (key == 2) {
                tweet *c = &twitter_system.news_feed[twitter_system.num_tweets]; //create the slot to insert the tweet
                post_tweet(usr, c, &twitter_system); //"usr will tweet message stored in c"
            }
            else if (key == 3) {
                newsfeed(usr, &twitter_system); //"print the news feed for usr"
            }
            else if (key == 4) {
                printf("Enter index of user that %s will unfollow ", usr->username);
                int index;
                scanf("%d", &index);
                user *b = &twitter_system.users[index]; //person usr will unfollow
                unfollow(usr, b); //"usr will unfollow b"
            }
            else if (key == 5) {
                deleteuser(usr, &twitter_system); //"usr will delete their account"/
                //increment i since each user is shifted one place to the left after a user is deleted
                i = i - 1;
            }
            else if (key == 6) {
                CloseTwitter();
            }
            else {
                printf("function out of range\n");
            }

            if (key != 5 ) {//when function executes ask user to input a new function
                printf("enter new key");
                scanf("%d", &key);
            }
            else {
                key = 0;
            }

        }
        if (key == 0) {
            nextuser(usr);
        }

        //reverse the counter if the loop is nearing it's end. this creates an infinite loop unless the CloseTwitter() function is called)
        if (i  == twitter_system.num_users - 2) {
            i = - 1;
        }
    }
}

//close twitter function
void CloseTwitter(void) {
    printf("You have chosen to close Twitter");
    exit(0);
}
