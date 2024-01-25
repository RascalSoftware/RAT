## Custom XY example Using Domains

This is an example of using incoherent summing ('domains') from custom 
XY models.

These are broadly the same as normal custom XY models, except that the
input to the custom function contains an additional 'domains' parameter.

``` matlab
function [output, subRough] = domainsCustomModel(params, bulkIn, bulkOut, contrast, domain)
```

This operates in the same way as the 'contrast' input parameter in that it
tells the function which case it should calculate. It always has a value 
of 1 or 2, denoting which is the current domain.
