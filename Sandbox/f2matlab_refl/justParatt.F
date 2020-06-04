      subroutine comp(out,x,sld,nbair,nbsub,ssub,nrepeats,resType,
     + resol,layers,points)
      integer size, i 
	integer layers,points,j,reploop
	double complex c0 , c1 , ci , beta , rij , N , M , MI , rimaj
	double complex blast , num , den , quo
	double complex pimag , pair , psub , plast
	real*8 pi , twopi , loop , nl , lam , nrepeats, ilow, ihi
	real*8 thick , q , theta, rho, rough, resol
	real*8 preal , snair , snsub , snlay, rfac, resType
	real*8 out(points,1),x(points,1),sld(layers,3)abeles_new_2.F
,nbair,nbsub,ssub
	real*8 dummydata(points,1), g(points,1)
	dimension N(2,2) , M(2,2) , MI(2,2)
	
	
	c0 = Dcmplx(0 , 0)
	c1 = Dcmplx(1 , 0)
	ci = Dcmplx(0 , 1)
	lam = 1.54
	pi = 3.141592653589
	rfac = ((4*pi)*(4*pi))/2
	twopi = 2*pi
	snair = (1.0 - dble(nbair*((lam*lam) / twopi)))
	snsub = (1.0 - dble(nbsub*((lam*lam) / twopi)))
	
	
	do loop = 1 , points
	    q = x(loop,1)
	    theta = asin(q*lam / (4*pi))
	    preal = ((snsub)*(snsub)) - ((snair)*(snair))*(cos(theta)**2)
	    psub = cdsqrt(preal*c1)
	    pair = snair*sin(theta)*c1
	    plast = pair
	    blast = 0.0
		rlast = sld(1,3)
	    MI(1 , 1) = c1
	    MI(2 , 2) = c1
	    MI(1 , 2) = c0
	    MI(2 , 1) = c0
		do reploop = 1, nrepeats
	    do nl = 1 , layers
			thick = sld(nl,1)
			rho = sld(nl,2)
			rough = sld(nl,3)

			
			snlay = (1 - dble(rho*((lam*lam) / twopi)))
			preal = (snlay*snlay) - (snair*snair) *cos(theta)**2
			pimag = cdsqrt(preal*c1)
			beta = (twopi / lam)*thick*pimag
			rij = dcmplx(plast - pimag) / dcmplx(plast + pimag)
			rij = rij * cdexp(-rfac*plast*pimag*(rough*rough)/(lam*lam)) 
			N(1 , 1) = cdexp(blast*ci)
			N(2 , 1) = rij * cdexp( - blast*ci)
			N(2 , 2) = cdexp( - blast*ci)
			N(1 , 2) = rij * cdexp(blast*ci)
			plast = pimag
			blast = beta
			rlast = rough
			call mcopy(MI , M)
			call mmult(M , N , MI)
	    end do
		end do
	    rij = (dcmplx(plast - psub)) / (dcmplx(plast + psub))
		rij = rij * cdexp(-rfac*plast*psub*(ssub*ssub)/(lam*lam)) 
	    N(1 , 1) = cdexp(blast*ci)
	    N(2 , 1) = rij*cdexp( - blast*ci)
	    N(2 , 2) = cdexp( - blast*ci)
	    N(1 , 2) = rij*cdexp(blast*ci)
	    call mcopy(MI , M)
	    call mmult(M , N , MI)
	    num = MI(2 , 1)*dconjg(MI(2 , 1))
	    den = MI(1 , 1)*dconjg(MI(1 , 1))
	    call cdiv(num , den , quo)
	    out(loop,1) = quo
	end do

			
	return
	end subroutine