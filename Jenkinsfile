pipeline 
{
    agent none
    stages 
    { 
       stage ('Build') 
       { 
            parallel 
            {
            
                stage('Build and Tests (Linux)') 
                {
                    agent 
                    {
                        label 'RAT_Linux'
                    }
                    environment
                    {
                        PATH = "/usr/local/MATLAB/R2021a/bin:${PATH}"
                    }
                    steps 
                    {

                        runMATLABCommand 'buildScript'
                        runMATLABCommand 'testRatScript'
                    }
                }
             
                stage('Build and Tests (Windows)') 
                {
                    agent 
                    {
                        label 'RAT_Windows'
                    }
                    environment
                    {
                        win_PATH = "C:\\Program Files\\MATLAB\\R2021a\\bin;${win_PATH}"
                    }
                    steps 
                    {
                        runMATLABCommand 'buildScript'
                        runMATLABCommand 'testRatScript'
                    }   

                }
            } // parallel

       }
        
    } // stages

} //pipeline
