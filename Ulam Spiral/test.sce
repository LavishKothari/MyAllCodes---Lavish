function DrawSpiral(filename)
    fid=mopen(filename,"r");
    [num_read,N]=mfscanf(fid, "%d");
    N
    M = hypermat([2*N+1 2*N+1]);
    for i=1:1+2*N
        for j=1:1+2*N
            [num_read,M(i,j)]=mfscanf(fid, "%d");
        end
    end
    mclose(fid);
    
    clf();
    ax = gca();//get current axes handle
    ax.data_bounds = [0, 0; 100, 100]; //set the data_bounds
    ax.box = 'on'; //draw a box
    Matplot1(M*20, [0,0,100,100])
endfunction


DrawSpiral('ulam.txt')
