C=======================================================================
C				Abeles Calculation for Matlab
C			
C out = abeles(xdata,sld,nbair,nbsub,ssub,repeats,s_between_repeats,resol)
C
C=======================================================================

#include "fintrf.h"
       subroutine mexfunction(nlhs, plhs, nrhs, prhs)
       mwPointer, external :: mxGetPr, mxCreateDoubleMatrix
       mwSize, external :: mxGetM, mxGetN
       integer nlhs, nrhs
       mwPointer plhs(*), prhs(*)
       mwPointer pr_in, pr_in2, pr_in3, pr_in4, pr_in5, pr_in6, pr_in7
       mwPointer pr_out, pr_in8
       integer m_in_q, n_in_q
       integer size, points, layers
       integer m_in_sld, n_in_sld


      if(nrhs .ne. 8) then
         call mexErrMsgTxt('8 inputs required to Abeles.')
      endif
      if(nlhs .gt. 1) then
         call mexErrMsgTxt('Less than one output required to Abeles.')
      endif

 
!	work out points         
      m_in_q = mxGetM(prhs(1))
      n_in_q = mxGetN(prhs(1))
	if (n_in_q .gt. 1) then
		call mexErrMsgTxt('Qz needs to be a column vector')
	endif
      points = m_in_q

!	do the same for layers
      m_in_sld = mxGetM(prhs(2))
      n_in_sld = mxGetN(prhs(2))
	if (n_in_sld .ne. 3) then
		call mexErrMsgTxt('SLD needs three columns: d r s')
	endif
	layers = m_in_sld


      pr_in = mxGetPr(prhs(1))
	pr_in2 = mxGetPr(prhs(2))
	pr_in3 = mxGetPr(prhs(3))
	pr_in4 = mxGetPr(prhs(4))
	pr_in5 = mxGetPr(prhs(5))
	pr_in6 = mxGetPr(prhs(6))
	pr_in7 = mxGetPr(prhs(7))
	pr_in8 = mxGetPr(prhs(8))

      plhs(1) = mxCreateDoubleMatrix(m_in_q, n_in_q, 0)
      pr_out = mxGetPr(plhs(1))

C     Call the computational routine.
      call comp(%val(pr_out),%val(pr_in),%val(pr_in2),%val(pr_in3),
     + %val(pr_in4),%val(pr_in5),%val(pr_in6),
     + %val(pr_in7),%val(pr_in8),layers,points)

      return
      end



C=========================================================================
c
C				computational routine.....
C
C=========================================================================

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

C	Do the resolution smearing


c	if (resType .EQ. 1) then
c		call resolution_mulf(out,x,out,out,resol,points)
c	endif

c	if (res_type .EQ. 2) then
		call resolution_polly(out,x,out,out,resol,points)
c	endif
			
	return
	end subroutine

c============================================================
c
c		Subroutine for resolution smearing..mulf version
c
c
c===========================================================
	subroutine resolution_mulf(out,xdata,ydata,dummyref,res,points)

	real*8 res,width,pi,numer,denom,Kval
	integer points,j,res_int,ilow,ihi,i
	real*8 xdata(points,1)
	real*8 ydata(points,1)
	real*8 out(points,1)
	real*8 dQbyQ,dQk,k,thisSumNumer,thisSumDenom
		

	pi = 3.141592653589793
	dQbyQ = res
	


	do k = 1 , points-1
		dQk = dQbyQ * xdata(k,1)
		width = dQk/2.35

		thisSumNumer = 0.0
		thisSumDenom = 0.0

		do j = 1,points-1
			numer = 1/(width * (sqrt(2*pi)))
			e_part = (xdata(k,1)-xdata(j,1))*(xdata(k,1)-xdata(j,1))
			e_part = e_part /(width*width)
			Kval = numer * exp(-(0.5*e_part))
			thisSumNumer = thisSumNumer + Kval * ydata(j,1)
			thisSumDenom = thisSumDenom + Kval
		end do
		out(k,1) = thisSumNumer / thisSumDenom
	end do

	out(points,1) = ydata(points,1)

	end subroutine

c============================================================
c
c		Subroutine for resolution smearing..polly version
c
c
c===========================================================


	subroutine resolution_polly(out,xdata,ydata,dummyref,res,points)

	real*8 res
	integer points,j,res_int,ilow,ihi,i
	real*8 xdata(points,1)
	real*8 ydata(points,1)
	real*8 dummyref(points,1)
	real*8 dummyydata(points,1)
	real*8 out(points,1)
	real*8 g,sumg

	res = res + 0.0001
	res_int = 10
	
	do j = 1,points
		sumg = 0
		dummyydata(j,1) = 0

		if (j .gt. 10) then
			ilow = -10
		else
			ilow = -j + 1
		endif

		if (j .lt. (points - 10)) then
			ihi = 10
		else
			ihi = points - j
		endif
		
		do i = ilow,ihi
		  g = exp(-1*((xdata(j+i,1)-xdata(j,1))/(res*xdata(j,1)))**2)
		  sumg = sumg + g
		  dummyydata(j,1) = dummyydata(j,1) + dummyref(i+j,1) * g
		end do
		if (sumg .ne. 0) then
			dummyydata(j,1) = dummyydata(j,1) / sumg
		endif
	end do

	out = dummyydata

	end subroutine



	! ----- -----------------------------
	SUBROUTINE CDIV(NUM , DEN , QUO)
	! SUBROUTINE TO DIVIDE COMPLEX NUMBERS
	! AND TRAP DIVIDE CHECKS
	double COMPLEX NUM , DEN , QUO , C1 , C0
	C1 = DCMPLX(1.0 , 0.0)
	C0 = DCMPLX(0.0 , 0.0)
	IF(DEN.EQ.NUM)THEN
	    QUO = C1
	    RETURN
	ENDIF
	IF(DEN.EQ.C0 )THEN
	    QUO = C0
	    RETURN
	ENDIF
	QUO = NUM / DEN
	RETURN
	END SUBROUTINE
	! ----- -------------------------------------------
	SUBROUTINE MMULT(A1 , A2 , A3)
	! SUBROUTINE FOR MATRIX MUTIPLICATION
	DOUBLE COMPLEX A1(2 , 2) , A2(2 , 2) , A3(2 , 2)
	A3(1 , 1) = A1(1 , 1)*A2(1 , 1) + A1(1 , 2)*A2(2 , 1)
	A3(1 , 2) = A1(1 , 1)*A2(1 , 2) + A1(1 , 2)*A2(2 , 2)
	A3(2 , 1) = A1(2 , 1)*A2(1 , 1) + A1(2 , 2)*A2(2 , 1)
	A3(2 , 2) = A1(2 , 1)*A2(1 , 2) + A1(2 , 2)*A2(2 , 2)
	RETURN
	END
	SUBROUTINE MCOPY(A1 , A2)
	! SUBROUTINE TO COPY A MATRIX
	DOUBLE COMPLEX A1(2 , 2) , A2(2 , 2)
	A2(1 , 1) = A1(1 , 1)
	A2(1 , 2) = A1(1 , 2)
	A2(2 , 1) = A1(2 , 1)
	A2(2 , 2) = A1(2 , 2)
	RETURN
	END	SUBROUTINE
