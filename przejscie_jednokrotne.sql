/******************************************************************************************************************/
--druga metoda to przeszukanie wszystkich elementow porownujec je ze saba.
/******************************************************************************************************************/
declare
    v_start_time TIMESTAMP WITH TIME ZONE ;
    v_end_time TIMESTAMP WITH TIME ZONE;
    x1_max number :=0;
    x2_max number :=0;
begin
    execute immediate 'alter system flush buffer_cache';
    execute immediate 'alter system flush shared_pool';
    dbms_output.put_line('wyszukiwanie najwiekszej i drugiej najwiekszej liczby na niepoindexowanym ');
    dbms_output.put_line('zbiorze 6.000.000 liczb rzeczywistych');
    dbms_output.put_line('druga metoda to przeszukanie wszystkich elementow porownujec je ze saba.');
    v_start_time := SYSTIMESTAMP;
    dbms_output.put_line('czas startu wyszukiwania: '|| TO_CHAR(v_start_time,'MM/DD/YYYY HH24:MI:SS:FF'));
    
    for a in (  select id, digit from stg_digits)
    loop
        if a.digit > x1_max then 
            x2_max := x1_max;
            x1_max := a.digit;
        elsif a.digit > x2_max then 
           x2_max := a.digit;
        end if;
    end loop;
    
    v_end_time := SYSTIMESTAMP;
    dbms_output.put_line('Pierwsza najwieksza liczba to: '||to_char(x1_max));
    dbms_output.put_line('Druga najwieksza liczba to: '||to_char(x2_max));
    dbms_output.put_line('czas zakonczenia wyszukiwania: '||TO_CHAR(v_end_time,'MM/DD/YYYY HH24:MI:SS:FF'));
    dbms_output.put_line('czas trwania wyszukiwania: '||to_char(v_end_time - v_start_time,'HH24:MI:SS:FF'));
end;    
/

select rownum as lp, id, digit 
from ( select id, digit from stg_digits order by digit desc )
where rownum<3;
