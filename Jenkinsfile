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

                        runMATLABCommand 'BuildScript'
                        runMATLABCommand 'TestRatScript'
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
                        runMATLABCommand 'BuildScript'
                        runMATLABCommand 'TestRatScript'
                    }   

                }
            } // parallel

       }
        
    } // stages

} //pipeline
