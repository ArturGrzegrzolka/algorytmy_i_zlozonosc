/******************************************************************************************************************/
/* trzecia metoda "pucharowa" to porownywanie par elementow ze soba. */
/******************************************************************************************************************/
declare
    cursor cur_liczby is 
    (   select * from 
        (   select id_pary, runda, max(digit) as winner, min(digit) loser from 
            (   select ceil(id/2) id_pary, 1 as runda, digit  from stg_digits order by id asc)
                group by  id_pary, runda
                order by id_pary) );
    type                    type_pary   is table of cur_liczby%rowtype index by binary_integer;
    t_pary                  type_pary;
    t_pary_working_copy     type_pary;
    r_prev_pary             cur_liczby%rowtype;
    v_id_pary               number:=0;
    v_runda                 number:=0;
    b                       number:=0;
    v_t_pary_last           number:=0;
    v_final_winner          number:=0;
    v_final_winner2         number:=0;
    x                       number:=0;
    v_start_time            TIMESTAMP WITH TIME ZONE ;
    v_end_time              TIMESTAMP WITH TIME ZONE;
begin
    execute immediate 'alter system flush buffer_cache';
    execute immediate 'alter system flush shared_pool';
    dbms_output.put_line('wyszukiwanie najwiekszej i drugiej najwiekszej liczby na');
    dbms_output.put_line('niepoindexowanym zbiorze 6.000.000 liczb rzeczywistych');
    dbms_output.put_line('trzecia metoda "pucharowa" to porownywanie par elementow ze soba.');
    v_start_time := SYSTIMESTAMP;
    dbms_output.put_line('czas startu losowania par do pierwszej rundy: '|| TO_CHAR(v_start_time,'MM/DD/YYYY HH24:MI:SS:FF'));
    
    t_pary.delete;
    t_pary_working_copy.delete;

    r_prev_pary:=null;
    v_final_winner:=0;
    v_final_winner2:=0;
    v_runda := 0;
    b:=0;
    v_id_pary:=0;
    
            open cur_liczby ;
            fetch  cur_liczby bulk collect into t_pary;
            close cur_liczby;
            t_pary_working_copy := t_pary;
            --------------------------------------------------------
                loop 
                    v_runda     := v_runda+1;
                    b           := 0;
                    v_id_pary   := 0;

                    --------------------------------------------------------
                    v_t_pary_last:=t_pary_working_copy.last;
                    --dbms_output.put_line('Ilosc par : '||t_pary.count);
                    --------------------------------------------------------
                    for a in t_pary.first..t_pary.last
                    loop
                        if t_pary(a).runda = v_runda then
                            b:=b+1;
                            v_id_pary                                   := ceil(b/2);
                            x                                           := v_t_pary_last+v_id_pary;
                                                        
                            t_pary_working_copy(x).runda        := v_runda+1;
                            t_pary_working_copy(x).id_pary      := v_id_pary;
                            
                            if mod(b,2)>0 then
                               r_prev_pary.winner               := greatest (t_pary(a).winner, t_pary(a).loser);
                               r_prev_pary.loser                := least    (t_pary(a).winner, t_pary(a).loser);
                               t_pary_working_copy(x).winner    := greatest (r_prev_pary.winner, r_prev_pary.loser);
                               t_pary_working_copy(x).loser     := least    (r_prev_pary.winner, r_prev_pary.loser);
                            else
                                t_pary_working_copy(x).winner   := greatest (t_pary(a).winner,r_prev_pary.winner) ;
                                t_pary_working_copy(x).loser    := least    (t_pary(a).winner,r_prev_pary.winner);
                            end if;
                        end if;s
                    end loop;
                    t_pary := t_pary_working_copy;
                    --dbms_output.put_line('v_ilosc_par_finalowych  : '||v_id_pary );
                exit when v_id_pary = 1 or v_runda >200;
                end loop;
                ------------------------------------------------------------------------
                dbms_output.put_line('after first round');
                v_final_winner := t_pary_working_copy(x).winner;
                v_final_winner2:= t_pary_working_copy(x).loser;
                dbms_output.put_line('final_winner : '||v_final_winner);
                dbms_output.put_line('final_winner2: '||v_final_winner2||' ;');
                ------------------------------------------------------------------------
                for a in t_pary.first..t_pary.last
                loop
                    if t_pary(a).winner = v_final_winner and t_pary(a).loser < v_final_winner then
                       v_final_winner2 := greatest(t_pary(a).loser,  v_final_winner2);
                    end if;
                end loop;
                --------------------------------------------------------
                dbms_output.put_line('after second round');
                dbms_output.put_line('final_winner : '||v_final_winner);
                dbms_output.put_line('final_winner2: '||v_final_winner2||' ;');
                
                v_end_time := SYSTIMESTAMP;
                dbms_output.put_line('ilosc rund potrzebnych do wyznaczenia finalistow: : '||v_runda);
                dbms_output.put_line('liczba najwieksza : '||v_final_winner);
                dbms_output.put_line('druga najwieksza liczba : '||v_final_winner2||' ;');
                dbms_output.put_line('czas zakonczenia wyszukiwania: '||TO_CHAR(v_end_time,'MM/DD/YYYY HH24:MI:SS:FF'));
                dbms_output.put_line('czas trwania calego wyszukiwania: '||to_char(v_end_time - v_start_time,'HH24:MI:SS:FF'));

                t_pary.delete;
                t_pary_working_copy.delete;
                r_prev_pary:=null;
                v_final_winner:=0;
                v_final_winner2:=0;       
                v_runda := 0;
                b:=0;
                v_id_pary:=0;
end;    
/


select rownum as lp, id, digit 
from ( select id, digit from stg_digits order by digit desc )
where rownum<3;
