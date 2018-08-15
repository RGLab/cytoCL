# cytoCL
Command line tools for cytolib

# TODO
Lots!

## Naming scheme
- do we want cytoxxx or something else. Personally the simpler the better.
* maybe opencyto_utilityname
* or oc_utilityname
## User interface
- I'm partial to the posix standard option format.
- I'd like the ability to use pipes between command line tools "|"

## Potential tools:
* FCS QC
  * cytofcscheck
      - perhaps 'fcscheck' simpler name.
  * cytofcs2h5
      - fcs2h5
  * cytofcsswap
      - what is this supposed to do? If swapping channel names etc, I think it's more a feature of a command line tool than
      a particular utility.
      
* flowJotoolset 
  * equivalent to flowJoWorkspace accessors, parser, gs accessors in R
   - how would this work from the comman line? 
   - See https://github.com/RGLab/opencytoCL for how I envision these tools working.
  * cytoxmlls,cytoxml2gs, cytogsls, cytogsstats
   - again these might be features of a single utility.

## FCS QC discussion
* goal
	* perpare the fcs for the openCyto gating
		* consistent channels or markers
		* report low count outliers?
		* Do some analysis of the time channel to identify potential problems
		* Same for FSC,SCC, could identify outlier samples.
		* consistent critical keyword (used for pdata)
* check items
  * channel consistency
    * num of params
    * name			
	    * typo (fuzzy matching ?)
	       - I wouldn't do fuzzy matching. Not at first.	      
	    * Maybe the user can specify expected names.
	       - would be painful for high-dimensional data but would work.
	    * case
  * marker
  * keyword
  	* supply a list of keys
  
*	QC report
	  * format
	      - good question.
	      - Something tabular.
    * recommending standardizing solutions
    	* params
	      * ~~swap chnls and markers~~
	          - I'd rather correct channel names and marker names. 
		  - We should provide such a utility.
		  - Same for keywords.
	      * drop redundant
	          - Yes consistency of channels is critical.
	      * correct typos
	          - See above.  We could read in a csv that specifies how files should be corrected
		      - need to think more about what it would look like.
      	* keywords
		* correct typos
		* report empty values?
      
* correct: (do we want to provide cli tools to do that?)
  * fcs is non-structural stream (data and txt is cat together) and designed for readonly
  * thus need to parse entire data and rewrite to new fcs/or h5? 
  * if so, maybe parse into h5 in the first place?
  * ~~or direct user to do it in R by the tips from qc report~~
  
                          
## FlowJo parsing QC discussion
* xml issue
	* channel discrepancy
		* case
		* prefix
			- gates refer to the unprefixed channel, but it meant to be prefixed, thus require the correction on xml
