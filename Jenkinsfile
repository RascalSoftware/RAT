pipeline {
    agent {
        label 'RAT_Linux'
    }
    environment {
        // PATH = "C:\\Program Files\\MATLAB\\R2021a\\bin;${PATH}"   // Windows agent
        //PATH="/opt/modules-common/software/MATLAB/R2020b/bin:${PATH}"   // Sethu VMLinux agent
        PATH = "/usr/local/MATLAB/R2021a/bin:${PATH}"                     // RAT_Linux 
        // PATH = "/Applications/MATLAB_R2021a.app/bin:${PATH}"   // macOS agent
    }
    stages {
        stage('Open Project env') {
            steps {
                runMATLABCommand '''RAT= openProject("RAT_demo.prj")'''
                //runMATLABCommand 'RAT = currentProject'
            }
        }
        stage('Run Tests') {
            steps {
                echo 'Temporarily Skipping this part' 
            }
        }
        stage('Code Generation') {
            steps {
                echo 'Temporarily Skipping this part' 
            }
        }
        stage('Run Sample Project'){
            steps {
               
                //sh('cd experimentJenkins')
                //runMATLABCommand 'DSPC.m'
                //runMATLABCommand'ls'
                //runMATLABCommand('cd tests')
                //runMATLABCommand'ls'
                //runMATLABCommand'cd experimentJenkins'
                //runMATLABCommand 'DSPC.m'
                ////runMATLABCommand 'pwd'
                ///runMATLABCommand 'addpath(genpath(pwd))'
                //runMATLABCommand 'addRatPaths'
                sh('pwd')
                runMATLABCommand '''addRatPaths_linux;cd 'tests';cd 'monolayer 8 contrasts';DSPCscript
                '''
                //dir('tests'){
                    //dir('monolayer 8 contrasts'){
                        //runMATLABCommand 'DSPCscript'
                    //}
                //}
                    
                

            }
        }
        
    }
}
