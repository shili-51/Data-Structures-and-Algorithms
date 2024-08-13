// multisource to multi destination - in order to calculate distance of each node from all the nodes (multiple source with multiple destinations)
// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

	void FloydWarshell(vector<vector<int>>&matrix){
	    // Code here
	    
	    for(int i = 0; i < matrix.size(); i++){
	        for(int j = 0; j < matrix[i].size(); j++){
	            
	           // from i to j its unreachable
	            if(matrix[i][j] == -1){
	                matrix[i][j] = 1e9;
	            }
	            
	            if(i == j) matrix[i][j] = 0;
	        }
	    }
	    
	    
	    for(int via = 0; via < matrix.size(); via++){
	        for(int i = 0; i < matrix.size(); i++){
	            for(int j = 0; j < matrix[i].size(); j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
	            }
	        }
	    }
	    
	    
	    
	    for(int i = 0; i < matrix.size(); i++){
	        for(int j = 0; j < matrix[i].size(); j++){
	            
	           // from i to j its unreachable
	            if(matrix[i][j] == 1e9){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
