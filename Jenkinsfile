pipeline 
{
    agent none
    stages 
    {

        // Start a parallel pool of n threads using matlab and Build it on linux
        stage ('Build on Windows, Linux') 
        {
            parallel 
            {
                stage('Build on Linux') 
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

                        runMATLABCommand '''BuildScript'''
                    }
                }

                // start a parallel pool of n threads using matlab and Build it on windows
                stage('Build on Windows') 
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
                        runMATLABCommand '''BuildScript'''
                    }   

                }


            }
        }

        stage ('Test on Windows, Linux') 
        {
            parallel 
            {
                stage ('Run Tests on Windows')
                {
                    agent
                    {
                        label 'RAT_Windows'
                    }
                    steps 
                    {
                        echo 'Running Test Script on Windows'
                        runMATLABCommand 'TestRatScript'
                    }

                }

                stage ('Run Tests on Linux')
                {

                    agent
                    {
                        label 'RAT_Linux'
                    }

                    steps 
                    {
                        echo 'Running Test Script on Linux'
                        runMATLABCommand 'TestRatScript'
                    }
                }
            }
        }
        
        
    } // stages

} //pipeline
