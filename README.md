# homework<br>my first ros homework

This file is distributed under the terms of the GNU Lesser General Public License (Lesser GPL)
A.Y. 2017/2018<br>
University of Verona (Italy)

![laboratorio ciberfisico homework_ros](ROS_industrial.jpg)
![laboratorio ciberfisico exit_homework_ros](exit_homework.jpg)

Homework is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with homework.
If not, see <http://www.gnu.org/licenses/>.

The files in homework contain the ROS based implementation for a simple publisher/subscriber mechanism.




The system has three nodes. The first node that sends the 
command does not send the data. The information starts from
a second node and is printed by a third node based on the 
commands of the first node. Data and commands travel on 
separate channels, so the node that prints will be entered
 in two topics.The data sent by the first node are known when 
the program is executed.The node that allows you to select from
 the keyboard which part of the message to show should behave
in the following way:
• Typing 'a' will print the entire message
• 'n' will only show the name
• 'and' will show only the age
• 'c' will show only the degree course



Please, report suggestions/comments/bugs to<br>
case-logic@hotmail.it.com