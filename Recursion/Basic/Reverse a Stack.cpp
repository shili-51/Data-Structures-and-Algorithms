// https://www.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-stack

class Solution{
public:
    
    void insert(stack<int> &St, int x){
        if(St.empty() == true){
            St.push(x);
            return;
        }
        else{
            int t = St.top();
            St.pop();
            insert(St,x);
            St.push(t);
        }
    }



    void Reverse(stack<int> &St){
        if(St.empty() == false){
            int temp = St.top();
            St.pop();
            Reverse(St);
            insert(St, temp);
        }
        
    }
};
