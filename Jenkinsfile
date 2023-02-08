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
                        sh 'mkdir build_linux'
                        sh 'cp -R compile/* build_linux/'
                        sh 'zip -r build_linux.zip build_linux -x "**/-lang:c++.zip"'
                        archiveArtifacts artifacts: 'build_linux.zip', onlyIfSuccessful: true
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
                        bat 'mkdir build_windows'
                        bat "xcopy /E /I compile build_windows"
                        bat 'tar --exclude="**/-lang:c++.zip" -acvf build_windows.zip build_windows'
                        archiveArtifacts artifacts: 'build_windows.zip', onlyIfSuccessful: true
                    }   
                }
            } // parallel
        }//build
        stage('Upload Linux Build') 
        {       
            agent { label 'RAT_Linux' }
            options { skipDefaultCheckout() }
            when { expression {env.BRANCH_NAME == 'master'} }
            steps 
            {
                withCredentials([usernamePassword(credentialsId: '2b162eff-3b08-4d6b-b004-799ea4c82929', 
                                                  usernameVariable: "GIT_USERNAME", passwordVariable: 'GIT_TOKEN')]) { 
                    sh 'python3 release.py ${GIT_TOKEN} build_linux.zip'
                }          
            }
        }//Upload linux build to GitHub from master
        stage('Upload Windows Build') 
        {          
            agent { label 'RAT_Windows' }
            options { skipDefaultCheckout() }  
            when { expression {env.BRANCH_NAME == 'master'} }
            steps 
            {  
                withCredentials([usernamePassword(credentialsId: '2b162eff-3b08-4d6b-b004-799ea4c82929', 
                                                  usernameVariable: "GIT_USERNAME", passwordVariable: 'GIT_TOKEN')]) { 
                                bat 'python release.py %GIT_TOKEN% build_windows.zip'
                }
            } 
        }//Upload windows build to GitHub from master
    } // stages
} //pipeline
