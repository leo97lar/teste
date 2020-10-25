
%figure
%hold on
%plot(1:100,trace(:,3),'O')
%errorbar(1:100,trace(:,3),trace(:,4),'.')

figure

plot(trace(:,1),trace(:,2));
hold on
plot(trace(:,1),trace(:,2),'.');
set(gca, 'fontsize', 18) 
xlabel('Generations','FontName','Arial','FontSize', 28);
ylabel('# surgeries out of term','FontName','Arial','FontSize', 28);
