.. image:: images/RATBanner.png
    :alt: RAT banner

|

.. _targetFunctions:

================
Target Functions
================

Reflectivity Calculation
-------------------------

reflectivity_calculation
##########################

.. automodule:: targetFunctions.reflectivity_calculation

.. autofunction:: reflectivity_calculation



.. _CommonFunctions:

Common Functions
----------------

Allocate Layers For Contrast
############################

.. automodule:: targetFunctions.common.groupLayers

.. autofunction:: allocateLayersForContrast

Allocate Params To Layers
#########################

.. automodule:: targetFunctions.common.groupLayers

.. autofunction:: allocateParamsToLayers


Back Sort
#########

.. automodule:: targetFunctions.common.backSorts

.. autofunction:: backSort



Chi-Squared
############

.. automodule:: targetFunctions.common.costFunctions.chiSquared

.. autofunction:: chiSquared


Group Layers Mod 
################

.. automodule:: targetFunctions.common.groupLayers

.. autofunction:: groupLayers_Mod


Loop Cpp Custlay Wrapper (Single,Points,Contrasts)
###################################################

.. automodule:: targetFunctions.common.loopCppCustlayWrapper

.. autofunction:: loopCppCustlayWrapper_CustLaycontrast


Loop Matlab Custom Wrapper (Single,Points,Contrasts)
#####################################################

.. automodule:: targetFunctions.common.loopMatlabCustomLayers.mexCompile

.. autofunction:: loopMatalbCustlayWrapper_CustLaycontrast


Shift Data
##########

.. automodule:: targetFunctions.common.shiftData

.. autofunction:: shiftdata


.. _StandardTF_reflectivityCalculation:

Standard Target Functions (StandardTF)
-----------------------------------------

.. image:: images/standTF.png


1. **Standard Layers (StanLay)**


standardTF Standard Layers - Single
####################################

.. automodule:: targetFunctions.standard_TF.standardTF_stanLay

.. autofunction:: standardTF_stanlay_single


standardTF Standard Layers - ParaPoints
#######################################

.. automodule:: targetFunctions.standard_TF.standardTF_stanLay

.. autofunction:: standardTF_stanlay_paraPoints


standardTF Standard Layers - ParaContrasts
###########################################

.. automodule:: targetFunctions.standard_TF.standardTF_stanLay

.. autofunction:: standardTF_stanlay_paraContrasts



2. **Custom Layers (CustLay)**


standardTF_custlay_single
##########################

.. automodule:: targetFunctions.standard_TF.standardTF_custLay

.. autofunction:: standardTF_custlay_single


standardTF_custlay_parapoints
#############################

.. automodule:: targetFunctions.standard_TF.standardTF_custLay

.. autofunction:: standardTF_custlay_paraPoints


standardTF_custlay_paraContrasts
################################

.. automodule:: targetFunctions.standard_TF.standardTF_custLay

.. autofunction:: standardTF_custlay_paraContrasts





3. **Custom XY (CustXY)**

standard_TF_custXY_single
##########################

.. automodule:: targetFunctions.standard_TF.standardTF_custXY

.. autofunction:: standardTF_custXY_single


standard_TF_custXY_parapoints
#############################

.. automodule:: targetFunctions.standard_TF.standardTF_custXY

.. autofunction:: standardTF_custXY_paraPoints


standard_TF_custXY_paraContrasts
################################

.. automodule:: targetFunctions.standard_TF.standardTF_custXY

.. autofunction:: standardTF_custXY_paraContrasts

