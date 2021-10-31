#pragma once
#include "alsqllnk.hpp"

namespace MetaDataForStudentTable {
	CSQLField id_field("DSTUDENTS_DBT", "id");
	signed long id;
	CSQLValue id_value(&id);

	CSQLField fn_field("DSTUDENTS_DBT", "first_name");
	char* first_name = new char[15];
	CSQLValue fn_value(first_name, 15);

	CSQLField ln_field("DSTUDENTS_DBT", "last_name");
	char* second_name = new char[15];
	CSQLValue ln_value(second_name, 15);

	CSQLField age_field("DSTUDENTS_DBT", "age");
	db_int32 age;
	CSQLValue age_value(&age);

	CSQLField year_field("DSTUDENTS_DBT", "year");
	db_int32 year;
	CSQLValue year_value(&year);

	CSQLField gender_field("DSTUDENTS_DBT", "gender");
	db_int32 gender;
	CSQLValue gender_value(&gender);

	CSQLField sumSubject_field(SQLCount(ln_field));
	db_int32 sumSubject;
	CSQLValue sumSubject_value(&sumSubject);
}

namespace MetaDataForStudyFeesTable {
	CSQLField idFees_field("DSTUDY_FEES_DBT", "id");
	signed long idFees;
	CSQLValue idFees_value(&idFees);

	CSQLField sum_field("DSTUDY_FEES_DBT", "sum");
	double sum;
	CSQLValue sum_value(&sum);

	CSQLField sId_field("DSTUDY_FEES_DBT", "student_id");
	signed long sId;
	CSQLValue sId_value(&sId);

}

namespace MetaDataForStudentTeacherClassTable {
	CSQLField cts_id_field("DSTUDENT_CLS_TCHR_LNK_DBT", "id");
	signed long cts_id;
	CSQLValue cts_id_value(&cts_id);

	CSQLField cts_sId_field("DSTUDENT_CLS_TCHR_LNK_DBT", "student_id");
	signed long cts_sId;
	CSQLValue cts_sId_value(&cts_sId);

	CSQLField cts_tId_field("DSTUDENT_CLS_TCHR_LNK_DBT", "teacher_id");
	signed long cts_tId;
	CSQLValue cts_tId_value(&cts_tId);

	CSQLField cts_cId_field("DSTUDENT_CLS_TCHR_LNK_DBT", "class_id");
	signed long cts_cId;
	CSQLValue cts_cId_value(&cts_cId);

}

namespace MetaDataForTeacherTable {
	CSQLField tchr_id_field("DTEACHERS_DBT", "id");
	signed long tchr_id;
	CSQLValue tchr_id_value(&tchr_id);

	CSQLField tchr_fn_field("DTEACHERS_DBT", "first_name");
	char* tchr_first_name = new char[15];
	CSQLValue tchr_fn_value(tchr_first_name, 15);

	CSQLField tchr_ln_field("DTEACHERS_DBT", "last_name");
	char* tchr_second_name = new char[15];
	CSQLValue tchr_ln_value(tchr_second_name, 15);

}

namespace MetaDataForClassTable {
	CSQLField c_id_field("DCLASSES_DBT", "id");
	signed long c_id;
	CSQLValue c_id_value(&c_id);

	CSQLField c_name_field("DCLASSES_DBT", "name");
	char* c_name = new char[15];
	CSQLValue c_name_value(c_name, 15);

}