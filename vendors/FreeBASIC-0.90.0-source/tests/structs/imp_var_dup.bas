
'' test for implicit vars with same name as structs

# include "fbcu.bi"

namespace fbc_tests.structs.imp_var_dup

type foo
	bar as integer
end type

sub test_basic cdecl ()
	dim as integer foo = 5678
	
	dim f as foo = ( 1234 )

	CU_ASSERT_EQUAL( f.bar, 1234 )
	CU_ASSERT_EQUAL( foo, 5678 )
end sub
	
private sub ctor () constructor

	fbcu.add_suite("fb-tests-structs:imp_var_dup")
	fbcu.add_test("test_basic", @test_basic)

end sub
	
end namespace