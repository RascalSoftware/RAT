.. _incoherent:


Incoherent Summing (Domains)
............................

When a sample contains domains of different compositions, how these are handled depends of the size of the domains relative to the lateral neutron coherence length (nC).
When domains are smaller than nC, we create the SLD profile as an average SLD of the domains, and calculate the reflectivity as normal. 
If the domains are larger that nC, instead we have to calculate the reflectivity from each domain separately, and then averege them. It is to calculate the latter type of 
domain that the 'domainClass' is used. As with 'normal reflectivity', we can handle domains with each of our calculations types:-

.. toctree::
   :maxdepth: 2

   domainsStanlay
   domainsCustomLayers