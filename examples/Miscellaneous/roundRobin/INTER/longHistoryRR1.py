
# Child algorithms of ReflectometryISISLoadAndProcess
LoadNexus(Filename='/archive/ndxinter/Instrument/data/cycle_18_1/INTER00049222.nxs', OutputWorkspace='TOF_49222')

## Child algorithms of ReflectometryReductionOneAuto
SpecularReflectionPositionCorrect(InputWorkspace='TOF_49222', TwoTheta=1, DetectorComponentName='point-detector', OutputWorkspace='__TMP0x6012700')

### Child algorithms of ReflectometryReductionOne
GroupDetectors(InputWorkspace='__TMP0x6012700', OutputWorkspace='__TMP0x6012000', GroupingPattern='3')
ConvertUnits(InputWorkspace='__TMP0x6012000', OutputWorkspace='__TMP0x73ca000', Target='Wavelength', AlignBins=True)
CropWorkspace(InputWorkspace='__TMP0x6012700', OutputWorkspace='__TMP0x6012000', StartWorkspaceIndex=2, EndWorkspaceIndex=2)
ConvertUnits(InputWorkspace='__TMP0x6012000', OutputWorkspace='__TMP0x8678e00', Target='Wavelength', AlignBins=True)
CalculateFlatBackground(InputWorkspace='__TMP0x8678e00', OutputWorkspace='__TMP0x8678380', StartX=17, EndX=18)
Integration(InputWorkspace='__TMP0x8678380', OutputWorkspace='__TMP0x8678a80', RangeLower=4, RangeUpper=10)
Divide(LHSWorkspace='__TMP0x73ca000', RHSWorkspace='__TMP0x8678a80', OutputWorkspace='__TMP0x6012000')
CropWorkspace(InputWorkspace='__TMP0x6012000', OutputWorkspace='__TMP0x73ca000', XMin=2, XMax=14)

#### Child algorithms of CreateTransmissionWorkspace
GroupDetectors(InputWorkspace='TRANS_49161', OutputWorkspace='__TMP0x6012000', GroupingPattern='3')
ConvertUnits(InputWorkspace='__TMP0x6012000', OutputWorkspace='__TMP0x8678a80', Target='Wavelength', AlignBins=True)
CropWorkspace(InputWorkspace='TRANS_49161', OutputWorkspace='__TMP0x6012000', StartWorkspaceIndex=2, EndWorkspaceIndex=2)
ConvertUnits(InputWorkspace='__TMP0x6012000', OutputWorkspace='__TMP0x8678380', Target='Wavelength', AlignBins=True)
CalculateFlatBackground(InputWorkspace='__TMP0x8678380', OutputWorkspace='__TMP0x8678e00', StartX=17, EndX=18)
Integration(InputWorkspace='__TMP0x8678e00', OutputWorkspace='__TMP0x8679180', RangeLower=4, RangeUpper=10)
Divide(LHSWorkspace='__TMP0x8678a80', RHSWorkspace='__TMP0x8679180', OutputWorkspace='__TMP0x6012000')
CropWorkspace(InputWorkspace='__TMP0x6012000', OutputWorkspace='__TMP0x8678a80', XMin=2, XMax=14)
GroupDetectors(InputWorkspace='TRANS_49160', OutputWorkspace='__TMP0x6012000', GroupingPattern='3')
ConvertUnits(InputWorkspace='__TMP0x6012000', OutputWorkspace='__TMP0x8679180', Target='Wavelength', AlignBins=True)
CropWorkspace(InputWorkspace='TRANS_49160', OutputWorkspace='__TMP0x6012000', StartWorkspaceIndex=2, EndWorkspaceIndex=2)
ConvertUnits(InputWorkspace='__TMP0x6012000', OutputWorkspace='__TMP0x8678e00', Target='Wavelength', AlignBins=True)
CalculateFlatBackground(InputWorkspace='__TMP0x8678e00', OutputWorkspace='__TMP0x8678380', StartX=17, EndX=18)
Integration(InputWorkspace='__TMP0x8678380', OutputWorkspace='__TMP0x8678700', RangeLower=4, RangeUpper=10)
Divide(LHSWorkspace='__TMP0x8679180', RHSWorkspace='__TMP0x8678700', OutputWorkspace='__TMP0x6012000')
CropWorkspace(InputWorkspace='__TMP0x6012000', OutputWorkspace='__TMP0x8679180', XMin=2, XMax=14)
Stitch1D(LHSWorkspace='__TMP0x8678a80', RHSWorkspace='__TMP0x8679180', OutputWorkspace='TRANS_LAM_49161_49160', StartOverlap=10, EndOverlap=12, ScaleRHSWorkspace=False)
#### End of child algorithms of CreateTransmissionWorkspace

RebinToWorkspace(WorkspaceToRebin='__TMP0x8679c00', WorkspaceToMatch='__TMP0x73ca000', OutputWorkspace='TRANS_LAM_49161_49160')
Divide(LHSWorkspace='__TMP0x73ca000', RHSWorkspace='__TMP0x8678a80', OutputWorkspace='')
ConvertUnits(InputWorkspace='__TMP0x8679180', OutputWorkspace='IvsQ_49222', Target='MomentumTransfer')
### End of child algorithms of ReflectometryReductionOne

Rebin(InputWorkspace='__TMP0x73ca000', OutputWorkspace='IvsQ_binned_49222', Params='0.00783435,-0.015,0.054582')
## End of child algorithms of ReflectometryReductionOneAuto
# End of child algorithms of ReflectometryISISLoadAndProcess

# Child algorithms of ReflectometryISISLoadAndProcess
LoadNexus(Filename='/archive/ndxinter/Instrument/data/cycle_18_1/INTER00049223.nxs', OutputWorkspace='TOF_49223')

## Child algorithms of ReflectometryReductionOneAuto
SpecularReflectionPositionCorrect(InputWorkspace='TOF_49223', TwoTheta=2.3999999999999999, DetectorComponentName='point-detector', OutputWorkspace='__TMP0x67f2700')

### Child algorithms of ReflectometryReductionOne
GroupDetectors(InputWorkspace='__TMP0x67f2700', OutputWorkspace='__TMP0x6c27c00', GroupingPattern='3')
ConvertUnits(InputWorkspace='__TMP0x6c27c00', OutputWorkspace='__TMP0x6c27500', Target='Wavelength', AlignBins=True)
CropWorkspace(InputWorkspace='__TMP0x67f2700', OutputWorkspace='__TMP0x6c27c00', StartWorkspaceIndex=2, EndWorkspaceIndex=2)
ConvertUnits(InputWorkspace='__TMP0x6c27c00', OutputWorkspace='__TMP0x6504380', Target='Wavelength', AlignBins=True)
CalculateFlatBackground(InputWorkspace='__TMP0x6504380', OutputWorkspace='__TMP0x6153c00', StartX=17, EndX=18)
Integration(InputWorkspace='__TMP0x6153c00', OutputWorkspace='__TMP0x6012000', RangeLower=4, RangeUpper=10)
Divide(LHSWorkspace='__TMP0x6c27500', RHSWorkspace='__TMP0x6012000', OutputWorkspace='__TMP0x6c27c00')
CropWorkspace(InputWorkspace='__TMP0x6c27c00', OutputWorkspace='__TMP0x6c27500', XMin=2, XMax=14)

#### Child algorithms of CreateTransmissionWorkspace
GroupDetectors(InputWorkspace='TRANS_49161', OutputWorkspace='__TMP0x6c27c00', GroupingPattern='3')
ConvertUnits(InputWorkspace='__TMP0x6c27c00', OutputWorkspace='__TMP0x6c26e00', Target='Wavelength', AlignBins=True)
CropWorkspace(InputWorkspace='TRANS_49161', OutputWorkspace='__TMP0x6c27c00', StartWorkspaceIndex=2, EndWorkspaceIndex=2)
ConvertUnits(InputWorkspace='__TMP0x6c27c00', OutputWorkspace='__TMP0x6c26a80', Target='Wavelength', AlignBins=True)
CalculateFlatBackground(InputWorkspace='__TMP0x6c26a80', OutputWorkspace='__TMP0x6013500', StartX=17, EndX=18)
Integration(InputWorkspace='__TMP0x6013500', OutputWorkspace='__TMP0x6012a80', RangeLower=4, RangeUpper=10)
Divide(LHSWorkspace='__TMP0x6c26e00', RHSWorkspace='__TMP0x6012a80', OutputWorkspace='__TMP0x6c27c00')
CropWorkspace(InputWorkspace='__TMP0x6c27c00', OutputWorkspace='__TMP0x6c26e00', XMin=2, XMax=14)
GroupDetectors(InputWorkspace='TRANS_49160', OutputWorkspace='__TMP0x6c27c00', GroupingPattern='3')
ConvertUnits(InputWorkspace='__TMP0x6c27c00', OutputWorkspace='__TMP0x6012a80', Target='Wavelength', AlignBins=True)
CropWorkspace(InputWorkspace='TRANS_49160', OutputWorkspace='__TMP0x6c27c00', StartWorkspaceIndex=2, EndWorkspaceIndex=2)
ConvertUnits(InputWorkspace='__TMP0x6c27c00', OutputWorkspace='__TMP0x6013500', Target='Wavelength', AlignBins=True)
CalculateFlatBackground(InputWorkspace='__TMP0x6013500', OutputWorkspace='__TMP0x6c26a80', StartX=17, EndX=18)
Integration(InputWorkspace='__TMP0x6c26a80', OutputWorkspace='__TMP0x6012380', RangeLower=4, RangeUpper=10)
Divide(LHSWorkspace='__TMP0x6012a80', RHSWorkspace='__TMP0x6012380', OutputWorkspace='__TMP0x6c27c00')
CropWorkspace(InputWorkspace='__TMP0x6c27c00', OutputWorkspace='__TMP0x6012a80', XMin=2, XMax=14)
Stitch1D(LHSWorkspace='__TMP0x6c26e00', RHSWorkspace='__TMP0x6012a80', OutputWorkspace='TRANS_LAM_49161_49160', StartOverlap=10, EndOverlap=12, ScaleRHSWorkspace=False)
#### End of child algorithms of CreateTransmissionWorkspace

RebinToWorkspace(WorkspaceToRebin='__TMP0x6504700', WorkspaceToMatch='__TMP0x6c27500', OutputWorkspace='TRANS_LAM_49161_49160')
Divide(LHSWorkspace='__TMP0x6c27500', RHSWorkspace='__TMP0x6c26e00', OutputWorkspace='')
ConvertUnits(InputWorkspace='__TMP0x6012a80', OutputWorkspace='IvsQ_49223', Target='MomentumTransfer')
### End of child algorithms of ReflectometryReductionOne

Rebin(InputWorkspace='__TMP0x6c27500', OutputWorkspace='IvsQ_binned_49223', Params='0.0188031,-0.015,0.131002')
## End of child algorithms of ReflectometryReductionOneAuto
# End of child algorithms of ReflectometryISISLoadAndProcess

# Child algorithms of ReflectometryISISLoadAndProcess
LoadNexus(Filename='/archive/ndxinter/Instrument/data/cycle_18_1/INTER00049224.nxs', OutputWorkspace='TOF_49224')

## Child algorithms of ReflectometryReductionOneAuto
SpecularReflectionPositionCorrect(InputWorkspace='TOF_49224', TwoTheta=4.5999999999999996, DetectorComponentName='point-detector', OutputWorkspace='__TMP0x7042000')

### Child algorithms of ReflectometryReductionOne
GroupDetectors(InputWorkspace='__TMP0x7042000', OutputWorkspace='__TMP0x7043180', GroupingPattern='3')
ConvertUnits(InputWorkspace='__TMP0x7043180', OutputWorkspace='__TMP0x61f9180', Target='Wavelength', AlignBins=True)
CropWorkspace(InputWorkspace='__TMP0x7042000', OutputWorkspace='__TMP0x7043180', StartWorkspaceIndex=2, EndWorkspaceIndex=2)
ConvertUnits(InputWorkspace='__TMP0x7043180', OutputWorkspace='__TMP0x61f8a80', Target='Wavelength', AlignBins=True)
CalculateFlatBackground(InputWorkspace='__TMP0x61f8a80', OutputWorkspace='__TMP0x61f8380', StartX=17, EndX=18)
Integration(InputWorkspace='__TMP0x61f8380', OutputWorkspace='__TMP0x67f3880', RangeLower=4, RangeUpper=10)
Divide(LHSWorkspace='__TMP0x61f9180', RHSWorkspace='__TMP0x67f3880', OutputWorkspace='__TMP0x7043180')
CropWorkspace(InputWorkspace='__TMP0x7043180', OutputWorkspace='__TMP0x61f9180', XMin=2, XMax=14)

#### Child algorithms of CreateTransmissionWorkspace
GroupDetectors(InputWorkspace='TRANS_49161', OutputWorkspace='__TMP0x7043180', GroupingPattern='3')
ConvertUnits(InputWorkspace='__TMP0x7043180', OutputWorkspace='__TMP0x67f3880', Target='Wavelength', AlignBins=True)
CropWorkspace(InputWorkspace='TRANS_49161', OutputWorkspace='__TMP0x7043180', StartWorkspaceIndex=2, EndWorkspaceIndex=2)
ConvertUnits(InputWorkspace='__TMP0x7043180', OutputWorkspace='__TMP0x61f8380', Target='Wavelength', AlignBins=True)
CalculateFlatBackground(InputWorkspace='__TMP0x61f8380', OutputWorkspace='__TMP0x61f8a80', StartX=17, EndX=18)
Integration(InputWorkspace='__TMP0x61f8a80', OutputWorkspace='__TMP0x6c27c00', RangeLower=4, RangeUpper=10)
Divide(LHSWorkspace='__TMP0x67f3880', RHSWorkspace='__TMP0x6c27c00', OutputWorkspace='__TMP0x7043180')
CropWorkspace(InputWorkspace='__TMP0x7043180', OutputWorkspace='__TMP0x67f3880', XMin=2, XMax=14)
GroupDetectors(InputWorkspace='TRANS_49160', OutputWorkspace='__TMP0x7043180', GroupingPattern='3')
ConvertUnits(InputWorkspace='__TMP0x7043180', OutputWorkspace='__TMP0x6c27c00', Target='Wavelength', AlignBins=True)
CropWorkspace(InputWorkspace='TRANS_49160', OutputWorkspace='__TMP0x7043180', StartWorkspaceIndex=2, EndWorkspaceIndex=2)
ConvertUnits(InputWorkspace='__TMP0x7043180', OutputWorkspace='__TMP0x61f8a80', Target='Wavelength', AlignBins=True)
CalculateFlatBackground(InputWorkspace='__TMP0x61f8a80', OutputWorkspace='__TMP0x61f8380', StartX=17, EndX=18)
Integration(InputWorkspace='__TMP0x61f8380', OutputWorkspace='__TMP0x6c26a80', RangeLower=4, RangeUpper=10)
Divide(LHSWorkspace='__TMP0x6c27c00', RHSWorkspace='__TMP0x6c26a80', OutputWorkspace='__TMP0x7043180')
CropWorkspace(InputWorkspace='__TMP0x7043180', OutputWorkspace='__TMP0x6c27c00', XMin=2, XMax=14)
Stitch1D(LHSWorkspace='__TMP0x67f3880', RHSWorkspace='__TMP0x6c27c00', OutputWorkspace='TRANS_LAM_49161_49160', StartOverlap=10, EndOverlap=12, ScaleRHSWorkspace=False)
#### End of child algorithms of CreateTransmissionWorkspace

RebinToWorkspace(WorkspaceToRebin='__TMP0x6012380', WorkspaceToMatch='__TMP0x61f9180', OutputWorkspace='TRANS_LAM_49161_49160')
Divide(LHSWorkspace='__TMP0x61f9180', RHSWorkspace='__TMP0x61f8a80', OutputWorkspace='')
ConvertUnits(InputWorkspace='__TMP0x6012000', OutputWorkspace='IvsQ_49224', Target='MomentumTransfer')
### End of child algorithms of ReflectometryReductionOne

Rebin(InputWorkspace='__TMP0x61f9180', OutputWorkspace='IvsQ_binned_49224', Params='0.0360438,-0.015,0.251118')
## End of child algorithms of ReflectometryReductionOneAuto
# End of child algorithms of ReflectometryISISLoadAndProcess

# Child algorithms of ReflectometryISISLoadAndProcess
LoadNexus(Filename='/archive/ndxinter/Instrument/data/cycle_18_1/INTER00049225.nxs', OutputWorkspace='TOF_49225')

## Child algorithms of ReflectometryReductionOneAuto
SpecularReflectionPositionCorrect(InputWorkspace='TOF_49225', TwoTheta=6, DetectorComponentName='point-detector', OutputWorkspace='__TMP0x8af8000')

### Child algorithms of ReflectometryReductionOne
GroupDetectors(InputWorkspace='__TMP0x8af8000', OutputWorkspace='__TMP0x8af9880', GroupingPattern='3')
ConvertUnits(InputWorkspace='__TMP0x8af9880', OutputWorkspace='__TMP0x6153880', Target='Wavelength', AlignBins=True)
CropWorkspace(InputWorkspace='__TMP0x8af8000', OutputWorkspace='__TMP0x8af9880', StartWorkspaceIndex=2, EndWorkspaceIndex=2)
ConvertUnits(InputWorkspace='__TMP0x8af9880', OutputWorkspace='__TMP0x67f2700', Target='Wavelength', AlignBins=True)
CalculateFlatBackground(InputWorkspace='__TMP0x67f2700', OutputWorkspace='__TMP0x67f3880', StartX=17, EndX=18)
Integration(InputWorkspace='__TMP0x67f3880', OutputWorkspace='__TMP0x6c26a80', RangeLower=4, RangeUpper=10)
Divide(LHSWorkspace='__TMP0x6153880', RHSWorkspace='__TMP0x6c26a80', OutputWorkspace='__TMP0x8af9880')
CropWorkspace(InputWorkspace='__TMP0x8af9880', OutputWorkspace='__TMP0x6153880', XMin=2, XMax=14)

#### Child algorithms of CreateTransmissionWorkspace
GroupDetectors(InputWorkspace='TRANS_49161', OutputWorkspace='__TMP0x8af9880', GroupingPattern='3')
ConvertUnits(InputWorkspace='__TMP0x8af9880', OutputWorkspace='__TMP0x6c26a80', Target='Wavelength', AlignBins=True)
CropWorkspace(InputWorkspace='TRANS_49161', OutputWorkspace='__TMP0x8af9880', StartWorkspaceIndex=2, EndWorkspaceIndex=2)
ConvertUnits(InputWorkspace='__TMP0x8af9880', OutputWorkspace='__TMP0x67f3880', Target='Wavelength', AlignBins=True)
CalculateFlatBackground(InputWorkspace='__TMP0x67f3880', OutputWorkspace='__TMP0x67f2700', StartX=17, EndX=18)
Integration(InputWorkspace='__TMP0x67f2700', OutputWorkspace='__TMP0x6c27c00', RangeLower=4, RangeUpper=10)
Divide(LHSWorkspace='__TMP0x6c26a80', RHSWorkspace='__TMP0x6c27c00', OutputWorkspace='__TMP0x8af9880')
CropWorkspace(InputWorkspace='__TMP0x8af9880', OutputWorkspace='__TMP0x6c26a80', XMin=2, XMax=14)
GroupDetectors(InputWorkspace='TRANS_49160', OutputWorkspace='__TMP0x8af9880', GroupingPattern='3')
ConvertUnits(InputWorkspace='__TMP0x8af9880', OutputWorkspace='__TMP0x6c27c00', Target='Wavelength', AlignBins=True)
CropWorkspace(InputWorkspace='TRANS_49160', OutputWorkspace='__TMP0x8af9880', StartWorkspaceIndex=2, EndWorkspaceIndex=2)
ConvertUnits(InputWorkspace='__TMP0x8af9880', OutputWorkspace='__TMP0x67f2700', Target='Wavelength', AlignBins=True)
CalculateFlatBackground(InputWorkspace='__TMP0x67f2700', OutputWorkspace='__TMP0x67f3880', StartX=17, EndX=18)
Integration(InputWorkspace='__TMP0x67f3880', OutputWorkspace='__TMP0x61f8380', RangeLower=4, RangeUpper=10)
Divide(LHSWorkspace='__TMP0x6c27c00', RHSWorkspace='__TMP0x61f8380', OutputWorkspace='__TMP0x8af9880')
CropWorkspace(InputWorkspace='__TMP0x8af9880', OutputWorkspace='__TMP0x6c27c00', XMin=2, XMax=14)
Stitch1D(LHSWorkspace='__TMP0x6c26a80', RHSWorkspace='__TMP0x6c27c00', OutputWorkspace='TRANS_LAM_49161_49160', StartOverlap=10, EndOverlap=12, ScaleRHSWorkspace=False)
#### End of child algorithms of CreateTransmissionWorkspace

RebinToWorkspace(WorkspaceToRebin='__TMP0x6013500', WorkspaceToMatch='__TMP0x6153880', OutputWorkspace='TRANS_LAM_49161_49160')
Divide(LHSWorkspace='__TMP0x6153880', RHSWorkspace='__TMP0x6c26a80', OutputWorkspace='')
ConvertUnits(InputWorkspace='__TMP0x6c27c00', OutputWorkspace='IvsQ_49225', Target='MomentumTransfer')
### End of child algorithms of ReflectometryReductionOne

Rebin(InputWorkspace='__TMP0x6153880', OutputWorkspace='IvsQ_binned_49225', Params='0.0470192,-0.015,0.327584')
## End of child algorithms of ReflectometryReductionOneAuto

# End of child algorithms of ReflectometryISISLoadAndProcess

Stitch1DMany(InputWorkspaces='IvsQ_49222,IvsQ_49223,IvsQ_49224,IvsQ_49225', OutputWorkspace='IvsQ_49222_49223_49224_49225', Params='-0.015', OutScaleFactors='1.01422,1.06288,1.09925')
