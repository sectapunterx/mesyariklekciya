cmake_minimum_required(VERSION 3.26)
project(mesyariklekciya)

set(CMAKE_CXX_STANDARD 17)


include_directories("C:/Users/Fin/.vcpkg-clion/vcpkg/installed/x64-windows/include")
include_directories("C:/Users/Fin/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic/include")
add_executable(4_3_calls_order 4_3_calls_order.cpp)
add_executable(4_4_casts_between_base_derived 4_4_casts_between_base_derived.cpp)
add_executable(4_5_multiple_inheritance 4_5_multiple_inheritance.cpp)
add_executable(5_1_idea_of_polymorphism.cpp 5_1_idea_of_polymorphism.cpp)
add_executable(5_3_abstract_classes.cpp 5_3_abstract_classes.cpp)
add_executable(5_4_virtual_destructors.cpp 5_4_virtual_destructors.cpp)
add_executable(5_5_RTTI.cpp 5_5_RTTI.cpp)
add_executable(6_1_intoduction_templates.cpp 6_1_intoduction_templates.cpp)
add_executable(6_2_template_func_overloading.cpp 6_2_template_func_overloading.cpp)
add_executable(6_3_template_specialization.cpp 6_3_template_specialization.cpp)
add_executable(6_4_non_type_template_parameters.cpp 6_4_non_type_template_parameters.cpp)
add_executable(6_6_dependent_names_problem.cpp 6_6_dependent_names_problem.cpp)
add_executable(6_7_basic_type_traits.cpp 6_7_basic_type_traits.cpp)
add_executable(3_10_enum.cpp 3_10_enum.cpp)
add_executable(7_0_exceptions.cpp 7_0_exceptions.cpp)
add_executable(7_2_dif_exceptions_re.cpp 7_2_dif_exceptions_re.cpp)
add_executable(7_3_throw_catch_mechanism.cpp 7_3_throw_catch_mechanism.cpp)
add_executable(8_2_idea_of_iterator.cpp 8_2_idea_of_iterator.cpp)
add_executable(8_3_myvector.cpp 8_3_myvector.cpp)
add_executable(8_5_deque.cpp 8_5_deque.cpp)
add_executable(8_7_map.cpp 8_7_map.cpp)
add_executable(9_1_allocators.cpp 9_1_allocators.cpp)
add_executable(9_1_1_myAllocator.cpp 9_1_1_myAllocator.cpp)
add_executable(9_4_new_delete_overload.cpp 9_4_new_delete_overload.cpp)
add_executable(9_5_alignments.cpp 9_5_alignments.cpp)
add_executable(10_move_semantics_rvalue_references.cpp 10_move_semantics_rvalue_references.cpp)
add_executable(10_2_The_Rule_of_Five.cpp 10_2_The_Rule_of_Five.cpp)
add_executable(10_4_def_lvalue_rvalue.cpp 10_4_def_lvalue_rvalue.cpp)
add_executable(10_5_reference_qualifiers.cpp 10_5_reference_qualifiers.cpp)
add_executable(10_6_perfect_forwarding_problem.cpp 10_6_perfect_forwarding_problem.cpp)
add_executable(10_7_std_forward.cpp 10_7_std_forward.cpp)
add_executable(10_8_copy_elision.cpp 10_8_copy_elision.cpp)
add_executable(11_type_deduction.cpp 11_type_deduction.cpp)
add_executable(12_1_unique_ptr.cpp 12_1_unique_ptr.cpp)
add_executable(12_2_shared_ptr.cpp 12_2_shared_ptr.cpp)
add_executable(13_lambdas.cpp 13_lambdas.cpp)