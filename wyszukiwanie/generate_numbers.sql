alter system flush buffer_cache;
alter system flush shared_pool;

CREATE TABLE ALGORYTMY.stg_digits
(	ID 		NUMBER, 
    digit	NUMBER
);
/

truncate table stg_digits;
declare
    v_starttime date;
    v_endtime date;
begin 
v_starttime := sysdate;
dbms_output.put_line(v_starttime);

    for a in 1..6000000
    loop
        insert into stg_digits (id, digit)
        select a,DBMS_RANDOM.VALUE(
                100000000 ,
                200000000 ) from dual;
    end loop;
    commit;
v_endtime:=sysdate;
dbms_output.put_line(v_endtime);
end;
/
