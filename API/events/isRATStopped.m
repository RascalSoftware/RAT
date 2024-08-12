function state = isRATStopped(IPCFilePath)
    % Checks if the stop event was set via the IPC file. The expected input
    % is the path to the inter-process communication file
    %
    % stopped = isRATStopped(filePath);
    if isempty(IPCFilePath)
        state = false;
        return
    end

    fileID = fopen(IPCFilePath);
    state = logical(fread(fileID, 1, '*uchar'));
    fclose(fileID);
end

