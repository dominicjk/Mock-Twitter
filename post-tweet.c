#include <stdio.h>
#include "post-tweet.h"

/*function takes three parameters, the user who is posting the tweet, the tweet message and the twitter system
 * The function first prompts the user to enter a message using fgets. Then the tweet is copied into the appropriate
 * message arrays, such as the tweet array in the twitter system.
 * Lastly, the number of tweets is incremented by one.
*/
void post_tweet(user* a, tweet* c, twitter *twitter_system) {
    //author of tweet will be a
    strcpy(c -> author, a);
    //prompt user and retrieve tweet
    printf("Enter Tweet\n");
    for (int i = 0; i < 2; i++) {
        fgets(&c->msg, TWEET_LENGTH, stdin);
    }
    
    //record tweet message and tweet author into twitter system arrays
    strcpy(&twitter_system->news_feed[twitter_system->num_tweets].msg, c -> msg);
    strcpy(&twitter_system->news_feed[twitter_system->num_tweets].author, a -> username);
    c -> id = twitter_system -> num_tweets;

    //increment number of tweets
    twitter_system -> num_tweets++;
}
