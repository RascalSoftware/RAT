
# Child algorithms of ReflectometryISISLoadAndProcess
LoadNexus(Filename='/archive/ndxinter/Instrument/data/cycle_18_1/INTER00049222.nxs', OutputWorkspace='TOF_49222')
ReflectometryReductionOneAuto(InputWorkspace='TOF_49222', ThetaIn=0.5, WavelengthMin=2, WavelengthMax=14, I0MonitorIndex=2, MonitorBackgroundWavelengthMin=17, MonitorBackgroundWavelengthMax=18, MonitorIntegrationWavelengthMin=4, MonitorIntegrationWavelengthMax=10, FirstTransmissionRun='TRANS_49161', SecondTransmissionRun='TRANS_49160', StartOverlap=10, EndOverlap=12, ScaleRHSWorkspace=False, MomentumTransferMin=0.0078343496021074845, MomentumTransferStep=0.014999999999999999, MomentumTransferMax=0.054582042880050204, ScaleFactor=1, OutputWorkspaceBinned='IvsQ_binned_49222', OutputWorkspace='IvsQ_49222', OutputWorkspaceWavelength='__TMP0x8679180', OutputWorkspaceTransmission='TRANS_LAM_49161_49160')
# End of child algorithms of ReflectometryISISLoadAndProcess

# Child algorithms of ReflectometryISISLoadAndProcess
LoadNexus(Filename='/archive/ndxinter/Instrument/data/cycle_18_1/INTER00049223.nxs', OutputWorkspace='TOF_49223')
ReflectometryReductionOneAuto(InputWorkspace='TOF_49223', ThetaIn=1.2, WavelengthMin=2, WavelengthMax=14, I0MonitorIndex=2, MonitorBackgroundWavelengthMin=17, MonitorBackgroundWavelengthMax=18, MonitorIntegrationWavelengthMin=4, MonitorIntegrationWavelengthMax=10, FirstTransmissionRun='TRANS_49161', SecondTransmissionRun='TRANS_49160', StartOverlap=10, EndOverlap=12, ScaleRHSWorkspace=False, MomentumTransferMin=0.018803147212319973, MomentumTransferStep=0.014999999999999999, MomentumTransferMax=0.13100183672511384, ScaleFactor=1, OutputWorkspaceBinned='IvsQ_binned_49223', OutputWorkspace='IvsQ_49223', OutputWorkspaceWavelength='__TMP0x6012a80', OutputWorkspaceTransmission='TRANS_LAM_49161_49160')
# End of child algorithms of ReflectometryISISLoadAndProcess

# Child algorithms of ReflectometryISISLoadAndProcess
LoadNexus(Filename='/archive/ndxinter/Instrument/data/cycle_18_1/INTER00049224.nxs', OutputWorkspace='TOF_49224')
ReflectometryReductionOneAuto(InputWorkspace='TOF_49224', ThetaIn=2.2999999999999998, WavelengthMin=2, WavelengthMax=14, I0MonitorIndex=2, MonitorBackgroundWavelengthMin=17, MonitorBackgroundWavelengthMax=18, MonitorIntegrationWavelengthMin=4, MonitorIntegrationWavelengthMax=10, FirstTransmissionRun='TRANS_49161', SecondTransmissionRun='TRANS_49160', StartOverlap=10, EndOverlap=12, ScaleRHSWorkspace=False, MomentumTransferMin=0.036043783767446338, MomentumTransferStep=0.014999999999999999, MomentumTransferMax=0.25111763593301817, ScaleFactor=1, OutputWorkspaceBinned='IvsQ_binned_49224', OutputWorkspace='IvsQ_49224', OutputWorkspaceWavelength='__TMP0x6012000', OutputWorkspaceTransmission='TRANS_LAM_49161_49160')
# End of child algorithms of ReflectometryISISLoadAndProcess

# Child algorithms of ReflectometryISISLoadAndProcess
LoadNexus(Filename='/archive/ndxinter/Instrument/data/cycle_18_1/INTER00049225.nxs', OutputWorkspace='TOF_49225')
ReflectometryReductionOneAuto(InputWorkspace='TOF_49225', ThetaIn=3, WavelengthMin=2, WavelengthMax=14, I0MonitorIndex=2, MonitorBackgroundWavelengthMin=17, MonitorBackgroundWavelengthMax=18, MonitorIntegrationWavelengthMin=4, MonitorIntegrationWavelengthMax=10, FirstTransmissionRun='TRANS_49161', SecondTransmissionRun='TRANS_49160', StartOverlap=10, EndOverlap=12, ScaleRHSWorkspace=False, MomentumTransferMin=0.047019235428652495, MomentumTransferStep=0.014999999999999999, MomentumTransferMax=0.32758378866109172, ScaleFactor=1, OutputWorkspaceBinned='IvsQ_binned_49225', OutputWorkspace='IvsQ_49225', OutputWorkspaceWavelength='__TMP0x6c27c00', OutputWorkspaceTransmission='TRANS_LAM_49161_49160')
# End of child algorithms of ReflectometryISISLoadAndProcess

Stitch1DMany(InputWorkspaces='IvsQ_49222,IvsQ_49223,IvsQ_49224,IvsQ_49225', OutputWorkspace='IvsQ_49222_49223_49224_49225', Params='-0.015', OutScaleFactors='1.01422,1.06288,1.09925')
