#include<bits/stdc++.h>
using namespace std;

//Using a function stack with getline and sstream
//TC=O(n)
//SC=o(n)


//Problem with using fee variable,see the stdout results, modify it or use another approach


/*Approach
1) Learn how to use getline() with sstream.
2) Declare a frequency array with size 'n' and initialized to 0. This will also be our result array.
3) Declare a stack which will store the tuple containing <ids of fxn,starttime of fxn,runtime of child_fxns> of fxns.
4) Iterate through the logs vector, for each string extract the id, whether it is starting or ending and the time stamp. Use getline with sstream to extract them.
5) For an extracted id 'i', if it is starting, push its id in the stack, if ending  pop it. Before popping we calculate its runtime using the end timestamp given by the log using getline and sstream, the starttime from the 2nd element of the tuple sitting on top of the stack and fee(runtime of child fxns) from the 3rd element of the tuple from the top of the stack. Note that whenever a fxn is ending, the top of the stack will always contain its log. This is due to the LIFO property of stack.
6) Update/Add the runtime calculated for the given fxn in the frequency/result vector. Now pop the log from the stack.
7) Check whether the stack is empty or not. If not, add the "time" calculated in STEP 5.
8) Run the loop until all logs are exausted.  

*/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        //Step 2
        vector<int> freq(n,0);
        //Step 3
        stack<tuple<string,int,int>> fxn; //The second parameter need to be a container like vector, hence we need to
        for(string& log:logs){       //pass the string and int as a pair
            string id,status,timestamp;
            int runtime,fee_init=0;
            //Step 4
            stringstream ss(log);
            getline(ss,id,':');
            getline(ss,status,':');
            getline(ss,timestamp,':');
            if(status == "start"){
                fxn.push({id,stoi(timestamp),fee_init});  //timestamp is a string, hence converting to int
            }
            else{
                //Step 5
                int starttime=get<1>(fxn.top()); //This gives the starttime of the just completed function.
                int fee = get<2>(fxn.top()); //This is runtime of all the child fxn of current fxn being popped.
                int time = stoi(timestamp)-starttime+1; //This is the runtime if no child fxn there. 
                runtime = time - fee;  //Subtract the fee, i.e the runtime of subroutines
                
                //Step 6
                freq[stoi(id)]+=runtime; //Update the runtime in the frequency array.
                fxn.pop();
                //Step 7
                if(!fxn.empty()) //This checks if stack is not empty.
                    get<2>(fxn.top())+=time; //Adding the time of child fxn to the parent function, note that we can
                    // not add runtime, since it denotes the effective runtime of the child fxn which might be 
                    // affected by the child fxn of the child fxn.
                    
            }
        }
        return freq;
    }
};
int main(){
    Solution sol;
    vector<string> logs = {"0:start:0","1:start:2","1:end:5","0:end:6"};
    vector<int> ans = sol.exclusiveTime(2,logs);
    for(int n : ans ){
        cout<< n << " ";
    }
}