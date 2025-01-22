 classdef testEventManager < matlab.unittest.TestCase   
    
   methods(TestMethodSetup)
       function reset(~)
         clear eventManager
      end
   end
   
   methods (TestClassTeardown)
       function clear(~)
           clear eventManager
       end
   end
   
   methods (Test)
      function testClear(testCase)
          % manually register two event handlers
          eventManager.clear();
          events = cell(2, 3);
          events(1, :) = {'disp', 0, @disp};
          events(2, :) = {'fprintf', 0, @fprintf};
          eventManager.setEvents(events);
          testCase.verifySize(eventManager.getEvents(), [2, 3]);
          eventManager.clear();
          testCase.verifySize(eventManager.getEvents(), [0, 3]);

          events = cell(3, 3);
          events(1, :) = {'disp', 0, @disp};
          events(2, :) = {'plot', 1, @plot};
          events(3, :) = {'fprintf', 0, @fprintf};
          eventManager.setEvents(events);
          testCase.verifySize(eventManager.getEvents(), [3, 3]);
          eventManager.clear(eventTypes.Plot);
          testCase.verifySize(eventManager.getEvents(), [2, 3]);
          events = eventManager.getEvents();
          testCase.verifyEqual(events(:, 1), {'disp'; 'fprintf'})
          testCase.verifyEqual(events(:, 2), {0; 0})
          testCase.verifyEqual(events(:, 3), {@disp; @fprintf})
          eventManager.clear(0);
          testCase.verifySize(eventManager.getEvents(), [0, 3]);
      end
      
      function testRegister(testCase)
          testCase.verifyError(@() eventManager.register('event', 'disp'), exceptions.invalidOption.errorID);
          testCase.verifyEmpty(eventManager.getEvents());
          testCase.verifyError(@() eventManager.register(eventTypes.Message, ''), exceptions.invalidType.errorID);
          testCase.verifyEmpty(eventManager.getEvents());
          testCase.verifyError(@() eventManager.register(eventTypes.Message, 2), exceptions.invalidType.errorID);
          testCase.verifyEmpty(eventManager.getEvents());
             
          eventManager.register(eventTypes.Message, 'disp');
          testCase.verifySize(eventManager.getEvents(), [1, 3]);
          testCase.verifyEqual(eventManager.getEvents(), {'disp', 0, @disp},  'eventManager.register is not working');
          anonymous = @(varargin) plot(varargin);
          id = func2str(anonymous);
          eventManager.register(eventTypes.Plot, anonymous);
          testCase.verifySize(eventManager.getEvents(), [2, 3]);
          testCase.verifyEqual(eventManager.getEvents(), {'disp', 0, @disp; id, 1, anonymous},  'eventManager.register is not working');
          eventManager.register(eventTypes.Message, @disp);
          testCase.verifySize(eventManager.getEvents(), [2, 3]);
          testCase.verifyEqual(eventManager.getEvents(), {'disp', 0, @disp; id, 1, anonymous},  'eventManager.register is not working');
          eventManager.register(eventTypes.Plot, @disp);
          testCase.verifySize(eventManager.getEvents(), [3, 3]);
          testCase.verifyEqual(eventManager.getEvents(), {'disp', 0, @disp; id, 1, anonymous; 'disp', 1, @disp},  'eventManager.register is not working');
      end
      
      function testUnregister(testCase)
          anonymous = @(varargin) plot(varargin);
          id = func2str(anonymous);
          eventManager.setEvents({'disp', 0, @disp; id, 1, anonymous; 'disp', 1, @disp});

          testCase.verifySize(eventManager.getEvents(), [3, 3]);
          testCase.verifyError(@() eventManager.unregister('event', 'disp'), exceptions.invalidOption.errorID);
          testCase.verifySize(eventManager.getEvents(), [3, 3]);
          testCase.verifyError(@() eventManager.unregister(eventTypes.Message, ''), exceptions.invalidType.errorID);
          testCase.verifySize(eventManager.getEvents(), [3, 3]);
          testCase.verifyError(@() eventManager.unregister(eventTypes.Message, 2), exceptions.invalidType.errorID);
          testCase.verifySize(eventManager.getEvents(), [3, 3]);
          
          eventManager.unregister(eventTypes.Plot, anonymous);
          testCase.verifyEqual(eventManager.getEvents(), {'disp', 0, @disp; 'disp', 1, @disp},  'eventManager.unregister is not working');
          eventManager.unregister(eventTypes.Plot, 'disp');
          testCase.verifyEqual(eventManager.getEvents(), {'disp', 0, @disp},  'eventManager.unregister is not working');
          eventManager.unregister(eventTypes.Plot, 'disp');
          testCase.verifyEqual(eventManager.getEvents(), {'disp', 0, @disp},  'eventManager.unregister is not working');
          eventManager.unregister(eventTypes.Message, @disp);
          testCase.verifyEmpty(eventManager.getEvents(),  'eventManager.unregister is not working');
      end
      
      function testNotify(testCase)
          % manually register message event handler
          events = cell(1, 3);
          events(1, :) = {'disp', 0, @disp};
          eventManager.setEvents(events);
          
          % send 'Hello world' to event handler
          display = evalc('eventManager.notify(0, "Hello World")');
          testCase.verifyEqual(strtrim(display), 'Hello World');

          % manually register two message event handlers
          events(end+1, :) = {'fprintf', 0, @fprintf};
          eventManager.setEvents(events);

          % send 'Hello' to both event handlers
          display = evalc('eventManager.notify(0, "Hello")');
          testCase.verifyEqual(strtrim(display), sprintf('Hello\nHello'));

          % manually register plot and message event handlers
          plotFn = mockFunction(testCase, 'fakePlot');
          printFn = mockFunction(testCase, 'fakePrint');
          events(1, :) = {'fakePrint', 0, @fakePrint};
          events(2, :) = {'fakePlot', 1, @fakePlot};
          eventManager.setEvents(events);
          % send plot event only so message is not called
          display = evalc('eventManager.notify(1, [1, 2, 3])');
          testCase.verifyEqual(display, '');
          testCase.verifyEqual(printFn.callCount, 0);
          testCase.verifyEqual(plotFn.callCount, 1);
          testCase.verifyEqual(plotFn.arguments{end}{1}, [1, 2, 3]);
          
          plotFn.exceptionID = 'RAT:invalidValue'; 
          display = evalc('eventManager.notify(1, "plotting")');
          testCase.verifyTrue(startsWith(display, 'EVENTMANAGER: calling fakePlot function failed on line 35 because'));
          testCase.verifyEqual(printFn.callCount, 0);
          testCase.verifyEqual(plotFn.callCount, 2);
          testCase.verifyEqual(plotFn.arguments{end}{1}, "plotting"); 
      end

      function testLivePlot(testCase)
         testCase.verifySize(eventManager.getEvents(), [0, 3]);
         [display, s] = evalc('useLivePlot(2)');
         testCase.verifySubstring(display, 'Live updating plot started in figure 2');
         testCase.verifySize(eventManager.getEvents(), [1, 3]);
         testCase.verifyEqual(eventManager.getEvents(), {'Function ''plotRefSLDHelper'' on figure 2', 1, s.handle},  'livePlot is not working');
         s.closeFigure()
         testCase.verifyEmpty(eventManager.getEvents());
         [display, s1] = evalc('useLivePlot(3)');
         testCase.verifySubstring(display, 'Live updating plot started in figure 3');
         testCase.verifySize(eventManager.getEvents(), [1, 3]);
         testCase.verifyEqual(eventManager.getEvents(), {'Function ''plotRefSLDHelper'' on figure 3', 1, s1.handle},  'livePlot is not working');
         [display, s2] = evalc('useLivePlot(5)');
         testCase.verifySubstring(display, 'Live updating plot started in figure 5');
         testCase.verifySize(eventManager.getEvents(), [1, 3]);
         testCase.verifyEqual(eventManager.getEvents(), {'Function ''plotRefSLDHelper'' on figure 5', 1, s2.handle},  'livePlot is not working');
         s1.closeFigure()
         testCase.verifySize(eventManager.getEvents(), [1, 3]);
         testCase.verifyEqual(eventManager.getEvents(), {'Function ''plotRefSLDHelper'' on figure 5', 1, s2.handle},  'livePlot is not working');
         s2.closeFigure()
         testCase.verifyEmpty(eventManager.getEvents());
      end

      function testStopEvent(testCase)
          controls = controlsClass();
          testCase.assertEmpty(controls.getIPCFilePath(), 'IPC is not working');
          controls.initialiseIPC();
          path = controls.getIPCFilePath();
          testCase.assertNotEmpty(path, 'IPC is not working');
          testCase.assertFalse(isRATStopped(path), 'IPC is not working');
          controls.sendStopEvent();
          testCase.assertTrue(isRATStopped(path), 'IPC is not working');
          testCase.assertFalse(isRATStopped(''), 'IPC is not working');
      end
   end
end
