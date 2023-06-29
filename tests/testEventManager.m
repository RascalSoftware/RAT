 classdef testEventManager < matlab.unittest.TestCase   
    
   methods(TestMethodSetup)
      function createBackground(testCase)
         clear eventManager
      end
   end

   methods (Test)
      function testClear(testCase)
          % manually register two event handlers
          eventManager.setEvents({0, 1});
          eventManager.setHandlers({'disp', 'fprintf'});
          testCase.verifyLength(eventManager.getEvents(), 2);

          mockFn = mockFunction(testCase, 'eventManagerInterface'); 
          eventManager.clear();

          testCase.verifyLength(eventManager.getEvents(), 0);
          testCase.verifyEqual(mockFn.callCount, 1);
          testCase.verifyEqual(mockFn.arguments{end}, {'clear'});
      end
      
      function testRegister(testCase)
          testCase.verifyError(@() eventManager.register('event', 'disp'), invalidType.errorID);
          testCase.verifyLength(eventManager.getEvents(), 0);
          testCase.verifyLength(eventManager.getHandlers(), 0);
          testCase.verifyError(@() eventManager.register(eventTypes.Message, ''), invalidType.errorID);
          testCase.verifyLength(eventManager.getEvents(), 0);
          testCase.verifyLength(eventManager.getHandlers(), 0);
          testCase.verifyError(@() eventManager.register(eventTypes.Message, 2), invalidType.errorID);
          testCase.verifyLength(eventManager.getEvents(), 0);
          testCase.verifyLength(eventManager.getHandlers(), 0);
            
          mockFn = mockFunction(testCase, 'eventManagerInterface');      
          eventManager.register(eventTypes.Message, "disp");
          testCase.verifyEqual(eventManager.getEvents(), {0},  'eventManager.register is not working');
          testCase.verifyEqual(eventManager.getHandlers(), {"disp"}, 'eventManager.register is not working');
          testCase.verifyEqual(mockFn.callCount, 1);
          testCase.verifyEqual(mockFn.arguments{end}, {'register', 0});
          eventManager.register(0, 'fprintf');
          testCase.verifyEqual(eventManager.getEvents(), {0, 0},  'eventManager.register is not working');
          testCase.verifyEqual(eventManager.getHandlers(), {"disp", 'fprintf'}, 'eventManager.register is not working');
          testCase.verifyEqual(mockFn.callCount, 1);
          eventManager.register(eventTypes.Plot, 'plot');
          testCase.verifyEqual(eventManager.getEvents(), {0, 0, 1},  'eventManager.register is not working');
          testCase.verifyEqual(eventManager.getHandlers(), {"disp", 'fprintf', 'plot'}, 'eventManager.register is not working');
          testCase.verifyEqual(mockFn.callCount, 2);
      end

      function testNotify(testCase)
          % manually register message event handler
          eventManager.setEvents({0});
          eventManager.setHandlers({'disp'}); 
          
          % send 'Hello world' to event handler
          display = evalc('eventManager.notify(0, "Hello World")');
          testCase.verifyEqual(strtrim(display), 'Hello World');

          % manually register two message event handlers
          eventManager.setEvents({0, 0});
          eventManager.setHandlers({'disp', 'fprintf'});

          % send 'Hello' to both event handlers
          display = evalc('eventManager.notify(0, "Hello")');
          testCase.verifyEqual(strtrim(display), sprintf('Hello\nHello'));

          % manually register plot and message event handlers
          plotFn = mockFunction(testCase, 'fakePlot');
          printFn = mockFunction(testCase, 'fakePrint'); 
          eventManager.setEvents({0, 1});
          eventManager.setHandlers({'fakePrint', 'fakePlot'});
          % send plot event only so message is not called
          display = evalc('eventManager.notify(1, [1, 2, 3])');
          testCase.verifyEqual(display, '');
          testCase.verifyEqual(printFn.callCount, 0);
          testCase.verifyEqual(plotFn.callCount, 1);
          testCase.verifyEqual(plotFn.arguments{end}{1}, [1, 2, 3]);
          
          plotFn.exceptionID = 'RAT:invalidValue'; 
          display = evalc('eventManager.notify(1, "plotting")');
          testCase.verifyTrue(startsWith(display, 'EVENTMANAGER: calling fakePlot function failed because'));
          testCase.verifyEqual(printFn.callCount, 0);
          testCase.verifyEqual(plotFn.callCount, 2);
          testCase.verifyEqual(plotFn.arguments{end}{1}, "plotting"); 
      end
   end
end
