# Send an HTML email with an embedded image and a plain text message for
# email clients that don't want to display the HTML.

from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.image import MIMEImage

# Define these once; use them twice!
email_user = 'MAILID'
email_password = 'PWD'
email_send = [Recipient list]


#Keep this Part safe
msgRoot = MIMEMultipart('related')
msgRoot['Subject'] = 'WCFL World Cup Form Response'
msgRoot['From'] = email_user
msgRoot['To'] = ','.join(email_send)
msgRoot.preamble = 'This is a multi-part message in MIME format.'

# Encapsulate the plain and HTML versions of the message body in an
msgAlternative = MIMEMultipart('alternative')
msgRoot.attach(msgAlternative)

#msgTest is where our entire Message for Response is put
msgText = MIMEText('Thank You all for your Responses, as promised I am back with my <b>exclusive insights on the World Cup Awards</b> based on your responses. I started circulating my Google FORM just 2 days before the World Cup Finals on July 15th.The responses were filled till the half time of FIFA World Cup Fianls.<br><br><br>The Winner of Prestigious awards are : <br>1. FIFA World Cup Winners - <b>France</b><br>2. Golden Ball - <b>Luka Modric</b><br>3. Golden Boot - <b>Harry Kane</b><br>4. Golden Glove - <b>Thibaut Courtois</b><br>5. Best Young Player - <b>Kylian Mbappe</b> <br>6. FIFA Fair Play Award -<b>Spain</b><br><br><p>All the Predictions with more than 50 % majority turned right except the World Cup Winners(As there were just 2 choices). Determining the winner of Best Young Player was very simple for FIFA due to a centum percent support for Kylian Mbappe, while for Golden Boot there was a 90 percent support for Harry Kane. For me the most intresting result was 55% support for Luka Modric to win Golden Ball. From this response I could make a decisive prediction that France will win the World Cup , since 1998 Losing Team most important player wins Golden Ball. Since there was just 41 responses I could not predict the complete results like the Fair Play award which was a surprise.The Goden glove went to 2nd most voted player Thibaut Courtois.<br><br> I would like to thank all of you for participating in this World Cup prediction competition even though there was no cash prize or any incentive.<p> <br><br> Regards, <br> Kurian Benoy <br>An automated message from Python', 'html')
msgAlternative.attach(msgText)

#This example assumes the Image Path in folder
fp = open('WCFLPictures/Screenshot from 2018-07-20 00-48-57.png',"rb")
msgImage = MIMEImage(fp.read())
fp.close()
msgImage.add_header('Content-ID', '<image1>')
msgRoot.attach(msgImage)
fp = open('WCFLPictures/Screenshot from 2018-07-20 00-48-38.png',"rb")
msgImage = MIMEImage(fp.read())
fp.close()
msgImage.add_header('Content-ID', '<image1>')
msgRoot.attach(msgImage)
fp = open('WCFLPictures/Screenshot from 2018-07-20 00-46-49.png',"rb")
msgImage = MIMEImage(fp.read())
fp.close()
#Define the image's ID as referenced above
msgImage.add_header('Content-ID', '<image1>')
msgRoot.attach(msgImage)

# Send the email (this example assumes SMTP authentication is required)
import smtplib
server = smtplib.SMTP('smtp.gmail.com',587)
server.starttls()
server.login(email_user,email_password)
server.sendmail(email_user,email_send,msgRoot.as_string())
server.quit()


