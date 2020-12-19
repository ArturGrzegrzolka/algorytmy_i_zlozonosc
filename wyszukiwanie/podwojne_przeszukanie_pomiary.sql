/******************************************************************************************************************/
--pierwsza metoda to podwójne przeszukanie wszystkich elementów (znajdujemy najwiekszy i drugi najwiekszy)
/******************************************************************************************************************/
declare
    v_start_time TIMESTAMP WITH TIME ZONE ;
    v_end_time TIMESTAMP WITH TIME ZONE;
    x1_max number               :=0;
    x2_max number               :=0;
    
    v_odc_pomiarowy number      :=1;
    v_last_odc_pomiarowy number :=5;
    
    v_pomiar number             :=1;
    v_last_pomiar number        :=10;
    
    v_rownum_poczatkowy number  :=1000000;
    v_rownum_krok number        :=1000000;
    v_rownum_koncowy number     :=6000000;
begin
    --execute immediate 'alter table liczby add constraint liczby_pk primary key (id)';
    execute immediate 'alter system flush buffer_cache';
    execute immediate 'alter system flush shared_pool';
    dbms_output.put_line('wyszukiwanie najwiekszej i drugiej najwiekszej liczby na ');
    dbms_output.put_line('niepoindexowanym zbiorze 6.000.000 liczb rzeczywistych');
    dbms_output.put_line('pierwsza metoda to podwójne przeszukanie wszystkich elementow zbioru.');
    dbms_output.put_line(' ');
    
    for x in v_odc_pomiarowy..v_last_odc_pomiarowy
    loop
        
        for y in v_pomiar..v_last_pomiar -- ilosc pomiarow w odcinku pomiarowym
        loop
            v_start_time := SYSTIMESTAMP;
            dbms_output.put_line('Odcinek '||v_odc_pomiarowy||'; pomiar '||y||'; Czas startu wyszukiwania: '|| TO_CHAR(v_start_time,'MM/DD/YYYY HH24:MI:SS:FF'));
            for a in (  select digit from stg_digits where id between v_rownum_poczatkowy and v_rownum_poczatkowy + v_rownum_krok)
            loop
                if a.digit > x1_max then 
                    x1_max := a.digit;
                end if;
            end loop;
            for a in (  select digit from stg_digits where id between v_rownum_poczatkowy and v_rownum_poczatkowy + v_rownum_krok)
            loop
                if a.digit > x2_max and a.digit < x1_max then 
                    x2_max := a.digit;
                end if;
            end loop;
            v_end_time := SYSTIMESTAMP;
            dbms_output.put_line('');
            dbms_output.put_line('Pierwsza najwieksza liczba to: '||to_char(x1_max));
            dbms_output.put_line('Druga najwieksza liczba to: '||to_char(x2_max));
            dbms_output.put_line('Czas zakonczenia wyszukiwania: '||TO_CHAR(v_end_time,'MM/DD/YYYY HH24:MI:SS:FF'));
            dbms_output.put_line('Odcinek '||v_odc_pomiarowy||'; pomiar '||y||'; Czas trwania wyszukiwania: '||to_char(v_end_time - v_start_time,'HH24:MI:SS:FF'));
            x1_max :=0;
            x2_max :=0;
        end loop;
        v_rownum_poczatkowy := v_rownum_poczatkowy+v_rownum_krok;
        v_odc_pomiarowy:=v_odc_pomiarowy+1;
    end loop;

end;    
/