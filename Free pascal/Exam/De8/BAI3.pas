Program bai3;
var d,m,y,n:integer;
function gt_d(m,y:integer):byte;
begin
  case m of
    1,3,5,7,8,10,12:gt_d:=31;
    4,6,9,11:gt_d:=30;
    2:if (y mod 4=0) and (y mod 100<>0) or (y mod 400=0) then
        gt_d:=29
      else
        gt_d:=28;
  end;
end;
procedure xuly;
var mm:byte;
    fi,fo:text;
begin
  assign(fi,'BAI3.INP');reset(fi);
  assign(fo,'BAI3.OUT');rewrite(fo);
  readln(fi,d,m,y);
  read(fi,n);
  d:=d+n;
  while d>gt_d(m,y) do
    begin
      d:=d-gt_d(m,y);
      inc(m);
      if m>12 then
        begin
          inc(y);
          m:=1;
        end;
    end;
  write(fo,d,' ',m,' ',y);
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.

