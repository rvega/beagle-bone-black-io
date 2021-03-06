# include "fbcu.bi"




const TEST_VALUE_1 = wstr( "123" )
const TEST_VALUE_2 = wstr( "456" )
const TEST_VALUE_3 = wstr( "789" )

test_data:
data TEST_VALUE_1, TEST_VALUE_2, TEST_VALUE_3	
data TEST_VALUE_1, TEST_VALUE_2, TEST_VALUE_3	

namespace fbc_tests.wstrings.data_

declare sub run_test( byval s1 as wstring ptr, byval s2 as wstring ptr )

sub test_1 cdecl ()
	dim ws as wstring * 32
	dim i as integer

	restore test_data
	for i = 1 to 2		
		read ws
		run_test( ws, TEST_VALUE_1 )

		read ws
		run_test( ws, TEST_VALUE_2 )

		read ws
		run_test( ws, TEST_VALUE_3 )
	next
end sub

sub test_2 cdecl ()
	dim b as byte, s as short, i as integer, l as longint, f as single, d as double
	
	restore test_data
	
	read b
	CU_ASSERT( b = cbyte( TEST_VALUE_1 ) )
	
	read s
	CU_ASSERT( s = cshort( TEST_VALUE_2 ) )

	read i
	CU_ASSERT( i = cint( TEST_VALUE_3 ) )

	read l
	CU_ASSERT( l = clngint( TEST_VALUE_1 ) )

	read f
	CU_ASSERT( f = csng( TEST_VALUE_2 ) )
	
	read d
	CU_ASSERT( d = cdbl( TEST_VALUE_3 ) )
	
	
end sub	
	
sub run_test( byval s1 as wstring ptr, byval s2 as wstring ptr )	
	
	CU_ASSERT( len( *s1 ) = len( *s2 ) )
	
	CU_ASSERT( *s1 = *s2 )
	
end sub

sub ctor () constructor

	fbcu.add_suite("fbc_tests.wstrings.data_")
	fbcu.add_test("test_1", @test_1)
	fbcu.add_test("test_2", @test_2)

end sub

end namespace
