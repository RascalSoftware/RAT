pipeline {
    agent any
    environment {
        // PATH = "C:\\Program Files\\MATLAB\\R2021a\\bin;${PATH}"   // Windows agent
        PATH="/opt/modules-common/software/MATLAB/R2020b/bin:${PATH}"   // Linux agent
        // PATH = "/Applications/MATLAB_R2021a.app/bin:${PATH}"   // macOS agent
    }
    stages {
        stage('Add Paths') {
            steps{
                runMATLABCommand 'addRatPaths' 
            }
        }
        stage('Run Files') {
            steps {
                echo 'Temporarily Skipping this part' 
            }
        }
        stage('Run Tests') {
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
                runMATLABCommand 'pwd'
                runMATLABCommand 'addpath(genpath(pwd))'
                //runMATLABCommand 'addRatPaths'
                runMATLABCommand 'tests/monolayer 8 contrasts/DSPCscript'
                    
                

            }
        }
        
    }
}
