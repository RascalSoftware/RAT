pipeline {
    agent none


    /*
    agent {
        label 'RAT_Linux' && 'RAT_Windows'
    }


    environment {
        win_PATH = "C:\\Program Files\\MATLAB\\R2021a\\bin;${win_PATH}"   // Windows agent NEED TO EDIT PIPELINE
        //PATH="/opt/modules-common/software/MATLAB/R2020b/bin:${PATH}"   // Sethu VMLinux agent
        PATH = "/usr/local/MATLAB/R2021a/bin:${PATH}"                     // RAT_Linux 
        // PATH = "/Applications/MATLAB_R2021a.app/bin:${PATH}"   // macOS agent
    }
    */


    stages {
        /*stage('Open Project env') {
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
        } */


        // BUILD ON Linux
        stage('Build Linux') {
            agent{
                label 'RAT_Linux'
            }
            environment{
                PATH = "/usr/local/MATLAB/R2021a/bin:${PATH}"
            }
            steps {
                runMATLABCommand 'pwd'
                runMATLABCommand ''' RAT = openProject("RAT_demo.prj")'''
                echo 'Project Env opened'
            }

            // Run Tests

            // Code Generation
        }


        // BUILD ON WINDOWS
        stage('Build on Windows'){
            agent {
                label 'RAT_Windows'
            }
            environment{
                win_PATH = "C:\\Program Files\\MATLAB\\R2021a\\bin;${win_PATH}"
            }
            steps {
                runMATLABCommand ''' RAT = openProject("RAT_demo.prj") '''
                echo 'Project Env opened'

                // Run Tests

                // Code Generation

            }
            
        }


        // BUILD ON macOS 
        /* 
        stage('Build macOS') {
            agent {
                label 'RAT_mac'
            }
            environment{
                PATH = "/Applications/MATLAB_R2021a.app/bin:${PATH}"
            }
            steps {
                runMATLABCommand ''' RAT = openProject("RAT_demo.prj") '''
                echo 'Project Env opened'
            }

            // Run Tests

            // Code Generation
        }
        */


               

        // run sample project on Windows,Linux,MacOS


        stage('Run Sample Project on Win') {
            agent{
                label 'RAT_Windows'
            }
            steps {
                runMATLABCommand 'pwd'
                runMATLABCommand ''' addRatPaths_win; cd tests;cd 'monolayer 8 contrasts';DSPCscript'''
            }
        }


        stage ('Run Sample Project on Linux') {
            agent{
                label 'RAT_Linux'
            }
            steps {
                runMATLABCommand 'pwd'
                runMATLABCommand ''' addRatPaths_linux; cd tests; cd 'monolayer 8 contrasts';DSPCscript'''
            }
        }

        //stage ('Run Sample Project on macOS') {
        //    agent{
        //        label 'RAT_MacOS'
        //   }
        //  steps {
        //        runMATLABCommand 'pwd'
        //        runMATLABCommand ''' addRatPaths_mac; cd tests; cd 'monolayer 8 contrasts';DSPCscript'''
        //    }
        //}

        stage ('Run Tests on Windows'){
            agent{
                label 'RAT_Windows'
            }
            steps {
                runMATLABCommand 'pwd'
                runMATLABCommand ''' cd testSuite; results = runtests'''
            }

        }

        stage ('Run Tests on Linux'){
            agent{
                label 'RAT_Linux'
            }
            steps {
                runMATLABCommand 'pwd'
                runMATLABCommand ''' cd testSuite; results = runtests'''
            }
        }

        //stage ('Run Tests on macOS'){
            //agent{
                // label 'RAT_mac'
            //}
            //steps {
                //runMATLABCommand 'pwd'
                //runMATLABCommand ''' cd testSuite; results = runtests'''
            //}
        //}
        
    
    }
}

