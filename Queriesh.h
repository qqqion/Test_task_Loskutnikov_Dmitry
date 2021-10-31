#pragma once
#include <iostream>

#include "alsqllnk.hpp"
#include "Namespaces.h"

void Query_1(CRsdConnection connection) {
	using namespace MetaDataForStudentTable;

	CSQLQueryRSD queryRSD((int)SQLQUERY_PARAM, &connection);
	signed long numOfStudents;
	CSQLValue num(&numOfStudents);

	queryRSD.SetSelect(1,
		SQLCount(id_field), num);

	if (queryRSD.moveFirst() == 0)
		std::cout << numOfStudents << std::endl;
}

void Query_2(CRsdConnection connection,
	CSQLCondition condition) {
	using namespace MetaDataForStudentTable;

	CSQLQueryRSD queryRSD((int)SQLQUERY_PARAM, &connection);
	queryRSD.SetSelect(6,
		id_field, id_value,
		fn_field, fn_value,
		ln_field, ln_value,
		age_field, age_value,
		year_field, year_value,
		gender_field, gender_value);
	queryRSD.whereCond = condition;

	while (queryRSD.moveNext() == 0)
		std::cout << id << " " << first_name
		<< " " << second_name << " " << age
		<< " " << year << " " << gender << std::endl;

}

void Query_3(CRsdConnection& connection,
	CSQLCondition condition) {
	using namespace MetaDataForStudyFeesTable;
	using namespace MetaDataForStudentTable;

	CSQLQueryRSD queryRSD((int)SQLQUERY_PARAM, &connection);
	queryRSD.SetSelect(5,
		id_field, id_value,
		fn_field, fn_value,
		ln_field, ln_value,
		sId_field, sId_value,
		SQLSum(sum_field), sum_value);
	queryRSD.joinCond = id_field == sId_field;
	queryRSD.SetGroupBy(1, sId_field);
	queryRSD.whereCond = condition;

	while (queryRSD.moveNext() == 0)
		std::cout << id << " " << sum
		<< " " << first_name << " " << second_name << std::endl;
}

void Query_4(CRsdConnection& connection) {
	using namespace MetaDataForClassTable;
	using namespace MetaDataForStudentTeacherClassTable;
	using namespace MetaDataForTeacherTable;

	CSQLQueryRSD queryRSD((int)SQLQUERY_PARAM, &connection);
	queryRSD.SetSelect(4,
		c_name_field, c_name_value,
		tchr_id_field, tchr_id_value,
		tchr_fn_field, tchr_fn_value,
		tchr_ln_field, tchr_ln_value);
	queryRSD.joinCond = c_id_field == cts_cId_field &&
		tchr_id_field == cts_tId_field;
	queryRSD.SetGroupBy(1, cts_tId_field);

	while (queryRSD.moveNext() == 0)
		std::cout << tchr_id << " " << tchr_first_name
		<< " " << tchr_second_name << " " << c_name << std::endl;
}

void Query_5(CRsdConnection& connection,
	CSQLCondition condition) {
	using namespace MetaDataForClassTable;
	using namespace MetaDataForStudentTeacherClassTable;
	using namespace MetaDataForStudentTable;

	CSQLQueryRSD queryRSD((int)SQLQUERY_PARAM, &connection);
	queryRSD.SetSelect(3,
		c_name_field, c_name_value,
		fn_field, fn_value,
		ln_field, ln_value);
	queryRSD.joinCond = c_id_field == cts_cId_field &&
		id_field == cts_sId_field;
	queryRSD.SetOrderBy(1, ln_field);

	while (queryRSD.moveNext() == 0)
		std::cout << first_name
		<< " " << second_name << " " << c_name << std::endl;
}