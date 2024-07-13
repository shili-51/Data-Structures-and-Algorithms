// https://www.geeksforgeeks.org/problems/sort-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sort-a-stack

void insert(stack<int>&s, int x){
    if(s.empty() == true || s.top() <= x){
        s.push(x);
        return;
    }else{
        int t = s.top();
        s.pop();
        insert(s,x);
        s.push(t);
    }
    
}


void SortedStack :: sort()
{
   //Your code here
   if(s.empty() == false){
       int x = s.top();
       s.pop();
       sort();
       insert(s,x);
   }
   
}
