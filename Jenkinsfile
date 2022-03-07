pipeline {
    options {
        timeout(time: 1, unit: 'MINUTES')
    }
    agent none
    stages {
        // Start a parallel pool of n threads using matlab and Build it on linux
        stage ('Starting Build on Windows, Linux') {
            parallel {
                stage('Build on Linux') {
                    agent {
                        label 'RAT_Linux'
                        }
                    environment{
                        PATH = "/usr/local/MATLAB/R2021a/bin:${PATH}"
                        }

                    steps {

                        echo 'Building Mex on Linux'
                        runMATLABCommand '''BuildScript'''
                        echo 'Building Mex on Linux complete'
                        }
                }

                // start a parallel pool of n threads using matlab and Build it on windows
                stage('Build on Windows') {
                    agent {
                        label 'RAT_Windows'
                    }
                    environment{
                        win_PATH = "C:\\Program Files\\MATLAB\\R2021a\\bin;${win_PATH}"
                    }

                    steps {
                        echo 'Building Mex on Windows'
                        runMATLABCommand '''BuildScript'''
                        echo 'Building Mex on Windows complete'
                    }   

                }

            }
        }

        stage ('Test on Windows, Linux') {
            parallel {
                stage ('Run Tests on Windows'){
                agent{
                    label 'RAT_Windows'
                }

                steps {
                    echo 'Starting parallel pool to compile and run tests on Windows'
                    runMATLABCommand 'TestRatScript'
                    echo 'Tests on Windows complete'

                    }

                }

                stage ('Run Tests on Linux'){
                    agent{
                    label 'RAT_Linux'
                        }

                    steps {
                    // 
                    echo 'Starting parallel pool to compile and run tests on Linux'
                    runMATLABCommand 'TestRatScript'
                    echo 'Tests on Linux complete'
                        } // end steps
                }// end stage

            }// end parallel
        }// end stage
                
        
    } // stages

} //pipeline
        
