#include <stdlib.h>
#include <stdio.h>

	This question is also quite popular, because it has real practical uses, specially during patching when version comparison is required
	The pseudocode is something like
	while( both version strings are not NULL )
	{

	// Extract the next version segment from Version string1.
	// Extract the next version segment from Version string2.
	// Compare these segments, if they are equal, continue
	// to check the next version segments.
	// If they are not equal, return appropriate code depending
	// on which segment is greater.
	 
	}
	And here is some code in PL-SQL
	---------------------------------------------------------------------
	compare_versions()
	Function to compare releases. Very useful when comparing file versions!
	This function compare two versions in pl-sql language. This function can compare
	Versions like 115.10.1 vs. 115.10.2 (and say 115.10.2 is greater), 115.10.1 vs. 115.10 (and say
	115.10.1 is greater), 115.10 vs. 115.10 (and say both are equal)
	---------------------------------------------------------------------
	function compare_releases(release_1 in varchar2, release_2 in varchar2) return boolean is
	release_1_str varchar2(132); release_2_str varchar2(132); release_1_ver number; release_2_ver number; ret_status boolean := TRUE; begin
	release_1_str := release_1 || '.'; release_2_str := release_2 || '.';
	while release_1_str is not null or release_2_str is not null loop
	-- Parse out a current version segment from release_1 if (release_1_str is null) then
	release_1_ver := 0;

	 
	else 1);
	 


	release_1_ver := nvl(to_number(substr(release_1_str,1, instr(release_1_str,'.')-1)),- release_1_str := substr(release_1_str,instr(release_1_str,'.')+1);
	 
	end if;
	-- Next parse out a version segment from release_2 if (release_2_str is null) then
	release_2_ver := 0;

	 
	else 1);

	end if;
	 


	release_2_ver := nvl(to_number(substr(release_2_str,1, instr(release_2_str,'.')-1)),- release_2_str := substr(release_2_str,instr(release_2_str,'.')+1);
	 

	if (release_1_ver > release_2_ver) then ret_status := FALSE;
	exit;
	elsif (release_1_ver < release_2_ver) then exit;
	end if;
	-- Otherwise continue to loop. end loop;
	return(ret_status);
	end compare_releases;